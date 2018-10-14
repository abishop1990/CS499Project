# Mongo DB Final Project For CS 340
# Requires simplejson, bson and MongoDB installation
# Requires you created a MongoDB database out of the 'stocks.json' file
#
# Written by Alan Bishop for CS 340 at SNHU 
# Last updated on 10/14/2018

#!/usr/bin/python
import json
import simplejson
import bson
from pymongo import MongoClient
import bottle
from bottle import route, run, request, abort

#Globals
HOST = 'localhost'
DB_NAME = 'market'
COLLECTION_NAME = 'stocks'
BOTTLE_PORT = 8080
MONGO_PORT = 27017
connection = MongoClient(HOST, MONGO_PORT)
collection = connection[DB_NAME][COLLECTION_NAME]

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

@route('/display_five_stocks', method='GET')
def display_five_stocks():
  ret = collection.find({'Ticker': {'$in': {request.query.one, request.query.two, request.query.three, request.query.four, request.query.five}}})
  return ret

if __name__ == '__main__':
	if connection is None:
		print("Couldn't find MongoClient connection to #{} on port #{}".format(HOST, MONGO_PORT))
	elif collection is None:
		print("Couldn't access collection")
	else: 
		run(host=HOST, port = BOTTLE_PORT)