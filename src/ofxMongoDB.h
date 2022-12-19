//
//  ofxMongoDB.hpp
//  this_again
//
//  Created by Fred Rodrigues on 31/08/2022.
//



#include <mongoc/mongoc.h>
#include "ofMain.h"


class ofxMongoDB {

public:

       mongoc_client_t *client;
       mongoc_collection_t *collection;
       mongoc_cursor_t *cursor;
       mongoc_database_t *database;

       
       const char *collection_name;
       const char *database_name;
       const char *uri_string;
       
       mongoc_uri_t *uri;

       void setup(const char * DB_URL, const char * databaseName, const char * collectionName);

       bool connect();

       ofJson getAllRecordsAsJSON();

       ofJson getFilteredRecordsAsJSON(const std::string& field, const std::string& value);

       ofJson getFilteredRecordsAsJSON(const std::string& field, int lower_value, int upper_value);

       void updateRecord(const std::string& field, const std::string& value, const std::string& oid);

       void close();
};



