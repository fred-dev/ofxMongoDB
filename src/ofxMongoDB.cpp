//
//  ofxMongoDB.cpp
//  this_again
//
//  Created by Fred Rodrigues on 31/08/2022.
//

#include "ofxMongoDB.h"


void ofxMongoDB::setup(const char * DB_URL, const char * databaseName, const char * collectionName) {
    collection_name = collectionName;
    uri_string = DB_URL;
    database_name  = databaseName;
}

bool ofxMongoDB::connect() {
    mongoc_init ();
    uri = mongoc_uri_new_with_error (uri_string, &error);
    if (!uri) {
        fprintf (stderr,
                 "failed to parse URI: %s\n"
                 "error message:       %s\n",
                 uri_string,
                 error.message);
        return false;
    }

    client = mongoc_client_new_from_uri (uri);
    mongoc_client_set_error_api (client, 2);

    database = mongoc_client_get_database(client, database_name);
    collection = mongoc_client_get_collection (client, database_name, collection_name);

    if  (!client) {
        return false;
    }

    return true;

}


ofJson ofxMongoDB::getAllRecordsAsJSON() {
    ofJson json;
    bson_error_t error;
    const bson_t *doc;
    bson_t query;
    
    bson_init (&query);
    cursor = mongoc_collection_find_with_opts (
                 collection,
                 &query,
                 NULL,  /* additional options */
                 NULL); /* read prefs, NULL for default */

    if (mongoc_cursor_error (cursor, &error)) {
        fprintf (stderr, "Cursor Failure: %s\n", error.message);
        return EXIT_FAILURE;
    }

    while (mongoc_cursor_next (cursor, &doc)) {
        json.push_back(json.parse(bson_as_json (doc, NULL)));
    }


    bson_destroy(&query);
    mongoc_cursor_destroy (cursor);

    return json;
}

void ofxMongoDB::close() {

    mongoc_collection_destroy (collection);
    mongoc_uri_destroy (uri);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

}

void ofxMongoDB::updateRecord(const std::string& field, const std::string& value, const std::string& oid) {

    bson_error_t error;
    bson_t* update_doc;
    bson_oid_t bson_oid;

    // Initialize the MongoDB driver and connect to the database
    mongoc_init();

    // Convert the oid string to a bson_oid_t
    bson_oid_init_from_string(&bson_oid, oid.c_str());

    // Create the update document
    update_doc = BCON_NEW("$set", "{", field.c_str(), value.c_str(), "}");

    // Update the field in the record
    mongoc_collection_update_one(
        collection,
        BCON_NEW("_id", BCON_OID(&bson_oid)),
        update_doc,
        NULL,
        NULL,
        &error);

    // Clean up
    bson_destroy(update_doc);
}


ofJson ofxMongoDB::getFilteredRecordsAsJSON(const std::string& field, const std::string& value) {

    bson_error_t error;
    bson_t* filter_doc;
    ofJson json;

    // Create the filter document
    filter_doc = BCON_NEW(field.c_str(), value.c_str());

    // Perform the find operation
    mongoc_cursor_t* cursor = mongoc_collection_find(
                                  collection,
                                  MONGOC_QUERY_NONE,
                                  0,
                                  0,
                                  0,
                                  filter_doc,
                                  NULL,
                                  NULL);

    if (mongoc_cursor_error (cursor, &error)) {
        fprintf (stderr, "Cursor Failure: %s\n", error.message);
        return EXIT_FAILURE;
    }

    // Iterate over the cursor and print the documents
    const bson_t* doc;
    while (mongoc_cursor_next(cursor, &doc)) {
        json.push_back(json.parse(bson_as_json (doc, NULL)));
    }

    // Clean up
    bson_destroy(filter_doc);
    mongoc_cursor_destroy (cursor);

    return json;
}


ofJson ofxMongoDB::getFilteredRecordsAsJSON(const std::string& field, int lower_value, int upper_value) {

    bson_error_t error;
    bson_t* filter_doc;
    ofJson json;

    // Create the filter document
    filter_doc = BCON_NEW(field.c_str(), "{", "$gte", BCON_INT32(lower_value), "$lte", BCON_INT32(upper_value), "}");

    // Perform the find operation
    mongoc_cursor_t* cursor = mongoc_collection_find(
                                  collection,
                                  MONGOC_QUERY_NONE,
                                  0,
                                  0,
                                  0,
                                  filter_doc,
                                  NULL,
                                  NULL);

    if (mongoc_cursor_error (cursor, &error)) {
        fprintf (stderr, "Cursor Failure: %s\n", error.message);
        return EXIT_FAILURE;
    }

    // Iterate over the cursor and print the documents
    const bson_t* doc;
    while (mongoc_cursor_next(cursor, &doc)) {
        json.push_back(json.parse(bson_as_json (doc, NULL)));
    }

    // Clean up
    bson_destroy(filter_doc);
    mongoc_cursor_destroy (cursor);

    return json;
}


