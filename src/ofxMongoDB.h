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
       bson_error_t error;
       const bson_t *doc;
       const char *collection_name;
       const char *database_name;

       bson_t query;
       char *str;
       const char *uri_string;
       mongoc_uri_t *uri;
    
    void setup(const char * DB_URL, const char * databaseName, const char * collectionName);
    
    bool connect();
    
    bool updateDocument();
    
    ofJson getDatabaseAsJSON();
    
    bool close();
};



