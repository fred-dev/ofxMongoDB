//
//  ofxMongoDB.hpp
//  this_again
//
//  Created by Fred Rodrigues on 31/08/2022.
//




#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>
#include <bsoncxx/exception/exception.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/exception/exception.hpp>


#include "ofMain.h"

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;


using namespace mongocxx;


class ofxMongoDB {
    
public:
    
    ofxMongoDB();
    mongocxx::client client;
    mongocxx::collection collection;
    mongocxx::database database;
    mongocxx::uri uri;

    std::string collection_name;
    std::string database_name;
    std::string uri_string;

    void setup(const char * DB_URL, const char * databaseName, const char * collectionName);
    bool connect();
    ofJson getAllRecordsAsJSON();
    ofJson getFilteredRecordsAsJSON_String(const std::string& field, const std::string& value);
    ofJson getFilteredRecordsAsJSON(const std::string& field, int lower_value, int upper_value);
    ofJson getFilteredRecordsAsJSON(const std::string& field, const bool value);
    ofJson getFilteredRecordsAsJsonFromCustomStringQuery(const std::string& filter_string);
    void updateRecord(const std::string& field, const std::string& value, const std::string& _oid);
    void updateRecord(const std::string& field, const float& value, const std::string& _oid);
    void updateRecord(const std::string& field, const int& value, const std::string& _oid);
    void updateRecord(const std::string& field, const bool& value, const std::string& _oid);

    void add_fields_to_entry_from_Json(const std::string& id_str, const ofJson& json);
    void insert_json_into_DB(const ofJson& json);
    void close();
};



