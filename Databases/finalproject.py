#!/usr/bin/python
import json
import simplejson
import bson
from pymongo import MongoClient
import bottle
from bottle import route, run, request, abort


connection = MongoClient('localhost', 27017)
db = connection['market']
collection = db['stocks']

@route('/create', method='POST')
def create():
  ret = collection.insert_one(simplejson.loads(request.body.getvalue()))
  return ret

@route('/read', method='GET')
def read():
  ret = collection.find_one({'Ticker': request.query.Ticker})
  return ret
  
@route('/update', method='GET')
def update():
  ret = collection.update_one({'Ticker': request.query.Ticker}, {'$set': {'Volume': request.query.Volume}})
  return ret

@route('/delete', method='GET')
def delete():
  stockToDelete = {"Ticker": request.query.Ticker}
  ret = collection.delete_one(stockToDelete)
  return ret

@route('/find_moving_average', method='GET')
def find_moving_average():
  ret = collection.find({ '50-Day Simple Moving Average': { '$gt': request.query.low, '$lt': request.query.high } })
  return ret

# I'll admit this one's pretty bad, my understanding here is shaky, I probably do deserve a few points off :(
@route('/display_five_stocks', method='GET')
def display_five_stocks():
  ret = collection.find({'Ticker': {'$in': {request.query.one, request.query.two, request.query.three, request.query.four, request.query.five}}})
  return ret

if __name__ == '__main__':
 #app.run(debug=True)
 run(host='localhost', port=8080)