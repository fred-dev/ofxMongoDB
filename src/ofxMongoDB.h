//
//  ofxMongoDB.hpp
//  this_again
//
//  Created by Fred Rodrigues on 31/08/2022.
//



#include <mongoc/mongoc.h>
#include <bson/bson.h>

#include "ofMain.h"

//using namespace mongocxx;
//using namespace bsoncxx;

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
    ofJson getAllRecordsAsJSON();
    ofJson getFilteredRecordsAsJSON(const std::string& field, const std::string& value);
    ofJson getFilteredRecordsAsJSON(const std::string& field, int lower_value, int upper_value);
    void updateRecord(const std::string& field, const std::string& value, const std::string& oid);
    void add_fields_to_entry_from_Json(const std::string& id_str, const ofJson& json);
    void insert_json_into_DB(const ofJson& json);
    void close();
};



