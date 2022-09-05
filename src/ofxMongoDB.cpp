//
//  ofxMongoDB.cpp
//  this_again
//
//  Created by Fred Rodrigues on 31/08/2022.
//

#include "ofxMongoDB.h"

void ofxMongoDB::setup(const char * DB_URL, const char * databaseName, const char * collectionName){
    collection_name = collectionName;
    uri_string = DB_URL;
    database_name  = databaseName;
}

bool ofxMongoDB::connect(){
    mongoc_init ();

    uri = mongoc_uri_new_with_error (uri_string, &error);
    if (!uri) {
       fprintf (stderr,
                "failed to parse URI: %s\n"
                "error message:       %s\n",
                uri_string,
                error.message);
       return EXIT_FAILURE;
    }

    client = mongoc_client_new_from_uri (uri);
    database = mongoc_client_get_database(client, database_name);
    collection = mongoc_client_get_collection (client, database_name, collection_name);

    if (!client) {
       return EXIT_FAILURE;
    }
    
        
}


ofJson ofxMongoDB::getDatabaseAsJSON(){
    ofJson json;
    mongoc_client_set_error_api (client, 2);

    bson_init (&query);
    cursor = mongoc_collection_find_with_opts (
       collection,
       &query,
       NULL,  /* additional options */
       NULL); /* read prefs, NULL for default */

    while (mongoc_cursor_next (cursor, &doc)) {
        json.push_back(json.parse(bson_as_json (doc, NULL)));
    }
    
    return json;
    
    if (mongoc_cursor_error (cursor, &error)) {
       fprintf (stderr, "Cursor Failure: %s\n", error.message);
       return EXIT_FAILURE;
    }
    
}

bool ofxMongoDB::close(){
    bson_destroy (&query);
    mongoc_cursor_destroy (cursor);
    mongoc_collection_destroy (collection);
    mongoc_uri_destroy (uri);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

}

bool ofxMongoDB::updateDocument(){
    bson_t *selector = BCON_NEW ("_id", "{", "$gt", BCON_UTF8 ("0wIv9yHgG1e98MyM"), "}");
    bson_t *update = BCON_NEW ("$set", "{", "cod", BCON_INT32 (999), "}");
    if (!mongoc_collection_update_one (
           collection, selector, update, NULL, NULL, &error)) {
       fprintf (stderr, "update failed: %s\n", error.message);
       return EXIT_FAILURE;
    }
    
    //update_one( cDocument{} << "_id" << "0wIv9yHgG1e98MyM" << finalize,
               //cDocument{} << "$set" << open_document <<
                          //  "cod" << 999 << close_document << finalize);
//    database->collection.update(
//       { _id: "0wIv9yHgG1e98MyM" },
//       {
//
//         $set: {
//           item: "ABC123",
//           "info.publisher": "2222",
//           tags: [ "software" ],
//           "ratings.1": { by: "xyz", rating: 3 }
//         }
//       }
//    )
}




