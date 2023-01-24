//
//  ofxMongoDB.cpp
//  this_again
//
//  Created by Fred Rodrigues on 31/08/2022.
//

#include "ofxMongoDB.h"

ofxMongoDB::ofxMongoDB(){
    // Initialize the MongoDB C++ driver
    static mongocxx::instance inst{};
    
}

void ofxMongoDB::setup(const char * DB_URL, const char * databaseName, const char * collectionName){
    collection_name = collectionName;
    uri_string = DB_URL;
    database_name  = databaseName;
}

bool ofxMongoDB::connect(){
    
    try {
        mongocxx::uri uri(uri_string);
        client = mongocxx::client(uri);
        
        database = client[database_name];
        collection = database[collection_name];
        
        return true;
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::connect")<<  "Error: " << e.what() << std::endl;
        return false;
    }
    
}


ofJson ofxMongoDB::getAllRecordsAsJSON(){
    ofJson json;
    try {
        mongocxx::cursor cursor = collection.find({});
        for (const auto& doc : cursor) {
            try {
                json.emplace_back(json.parse(bsoncxx::to_json(doc)));
            } catch (const std::exception& e) {
                ofLogError("ofxMongoDB::getAllRecordsAsJSON") << "Error: Failed to parse document as JSON: " << e.what() << std::endl;
            }
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::getAllRecordsAsJSON") << "Error: " << e.what() << std::endl;
    }
    
    return json;
}

void ofxMongoDB::close(){
    
    
    
}

void ofxMongoDB::updateRecord(const std::string& field, const std::string& value, const std::string& _oid) {
    
    // First, we need to parse the ID string into a bsoncxx::oid object
    bsoncxx::oid id;
    try {
        id = bsoncxx::oid(_oid);
    } catch (const bsoncxx::exception& e) {
        
        ofLogError("ofxMongoDB::updateRecord")<< "Error parsing ID string: " << e.what() << std::endl;
        return;
    }
    
    // Next, we create the update object that will set the specified field to the new value
    // We use the "$set" update operator to specify that we want to update the field, rather than overwrite the entire document
    auto update = make_document(kvp("$set", make_document(kvp(field, value))));
    
    // Finally, we can perform the update operation using the update_one method of the collection object
    try {
        auto result = collection.update_one(make_document(kvp("_id", id)), update.view());
        if (result) {
            ofLogVerbose("ofxMongoDB::updateRecord") << "Successfully updated record with ID: " << _oid << std::endl;
        } else {
            ofLogError("ofxMongoDB::updateRecord")<< "Error updating record with ID: " << _oid << std::endl;
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::updateRecord") << "Error updating record: " << e.what() << std::endl;
    }
}
void ofxMongoDB::updateRecord(const std::string& field, const float& value, const std::string& _oid){
    // First, we need to parse the ID string into a bsoncxx::oid object
    bsoncxx::oid id;
    try {
        id = bsoncxx::oid(_oid);
    } catch (const bsoncxx::exception& e) {
        
        ofLogError("ofxMongoDB::updateRecord")<< "Error parsing ID string: " << e.what() << std::endl;
        return;
    }
    
    // Next, we create the update object that will set the specified field to the new value
    // We use the "$set" update operator to specify that we want to update the field, rather than overwrite the entire document
    auto update = make_document(kvp("$set", make_document(kvp(field, value))));
    
    // Finally, we can perform the update operation using the update_one method of the collection object
    try {
        auto result = collection.update_one(make_document(kvp("_id", id)), update.view());
        if (result) {
            ofLogVerbose("ofxMongoDB::updateRecord") << "Successfully updated record with ID: " << _oid << std::endl;
        } else {
            ofLogError("ofxMongoDB::updateRecord")<< "Error updating record with ID: " << _oid << std::endl;
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::updateRecord") << "Error updating record: " << e.what() << std::endl;
    }
}
void ofxMongoDB::updateRecord(const std::string& field, const int& value, const std::string& _oid){
    // First, we need to parse the ID string into a bsoncxx::oid object
    bsoncxx::oid id;
    try {
        id = bsoncxx::oid(_oid);
    } catch (const bsoncxx::exception& e) {
        
        ofLogError("ofxMongoDB::updateRecord")<< "Error parsing ID string: " << e.what() << std::endl;
        return;
    }
    
    // Next, we create the update object that will set the specified field to the new value
    // We use the "$set" update operator to specify that we want to update the field, rather than overwrite the entire document
    auto update = make_document(kvp("$set", make_document(kvp(field, value))));
    
    // Finally, we can perform the update operation using the update_one method of the collection object
    try {
        auto result = collection.update_one(make_document(kvp("_id", id)), update.view());
        if (result) {
            ofLogVerbose("ofxMongoDB::updateRecord") << "Successfully updated record with ID: " << _oid << std::endl;
        } else {
            ofLogError("ofxMongoDB::updateRecord")<< "Error updating record with ID: " << _oid << std::endl;
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::updateRecord") << "Error updating record: " << e.what() << std::endl;
    }
}
void ofxMongoDB::updateRecord(const std::string& field, const bool& value, const std::string& _oid){
    // First, we need to parse the ID string into a bsoncxx::oid object
    bsoncxx::oid id;
    try {
        id = bsoncxx::oid(_oid);
    } catch (const bsoncxx::exception& e) {
        
        ofLogError("ofxMongoDB::updateRecord")<< "Error parsing ID string: " << e.what() << std::endl;
        return;
    }
    
    // Next, we create the update object that will set the specified field to the new value
    // We use the "$set" update operator to specify that we want to update the field, rather than overwrite the entire document
    auto update = make_document(kvp("$set", make_document(kvp(field, value))));
    
    // Finally, we can perform the update operation using the update_one method of the collection object
    try {
        auto result = collection.update_one(make_document(kvp("_id", id)), update.view());
        if (result) {
            ofLogVerbose("ofxMongoDB::updateRecord") << "Successfully updated record with ID: " << _oid << std::endl;
        } else {
            ofLogError("ofxMongoDB::updateRecord")<< "Error updating record with ID: " << _oid << std::endl;
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::updateRecord") << "Error updating record: " << e.what() << std::endl;
    }
}

ofJson ofxMongoDB::getFilteredRecordsAsJSON_String(const std::string& field, const std::string& value) {
    ofJson json;
    try {
        mongocxx::cursor cursor = collection.find(document{} << field << open_document << "$regex" << value << "$options" << "i" << close_document << finalize);
        //mongocxx::cursor cursor = collection.find(document{} << field << value << finalize);
        //mongocxx::cursor cursor = collection.find(document{} << field << open_document << "$eq" << value << close_document << finalize);
        for (const auto& doc : cursor) {
            try {
                cout<<"Record" << endl;

                json.emplace_back(json.parse(bsoncxx::to_json(doc)));
            } catch (const std::exception& e) {
                ofLogError("ofxMongoDB::getFilteredRecordsAsJSON") << "Error: Failed to parse document as JSON: " << e.what() << std::endl;
            }
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::getFilteredRecordsAsJSON") << "Error: " << e.what() << std::endl;
    }
    return json;
}


ofJson ofxMongoDB::getFilteredRecordsAsJSON(const std::string& field, const bool value) {
    ofJson json;
    try {
        mongocxx::cursor cursor = collection.find(document{} << field << value << finalize);
        for (const auto& doc : cursor) {
            try {
                json.emplace_back(json.parse(bsoncxx::to_json(doc)));
            } catch (const std::exception& e) {
                ofLogError("ofxMongoDB::getFilteredRecordsAsJSON") << "Error: Failed to parse document as JSON: " << e.what() << std::endl;
            }
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::getFilteredRecordsAsJSON") << "Error: " << e.what() << std::endl;
    }
    
    return json;
}
ofJson ofxMongoDB::getFilteredRecordsAsJSON(const std::string& field, int lower_value, int upper_value) {
    ofJson json;
    try {
        mongocxx::cursor cursor = collection.find(
                                                  document{} << field << open_document <<
                                                  "$gt" << lower_value <<
                                                  "$lte" << upper_value
                                                  << close_document << finalize);
        for (const auto& doc : cursor) {
            try {
                json.emplace_back(json.parse(bsoncxx::to_json(doc)));
            } catch (const std::exception& e) {
                ofLogError("ofxMongoDB::getFilteredRecordsAsJSON") << "Error: Failed to parse document as JSON: " << e.what() << std::endl;
            }
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::getFilteredRecordsAsJSON") << "Error: " << e.what() << std::endl;
    }
    
    return json;
}


void ofxMongoDB::add_fields_to_entry_from_Json(const std::string& id_str, const ofJson& json) {
    // First, we need to parse the ID string into a bsoncxx::oid object
    ofLogVerbose("ofxMongoDB::add_fields_to_entry_from_Json") << "Attempting to add new fields (or update existing) from JSON for id: " << id_str << std::endl;

    bsoncxx::oid id;
    try {
        id = bsoncxx::oid(id_str);
    } catch (const bsoncxx::exception& e) {
        ofLogError("ofxMongoDB::add_fields_to_entry_from_Json") << "Error parsing ID string: " << e.what() << std::endl;
        return;
    }
    // Next, we create a MongoDB document object from the ofJson object
    bsoncxx::document::value doc = bsoncxx::from_json(json.dump());
    
    // Now we can create the update object that will add the new fields to the entry
    // We use the "$set" update operator to specify that we only want to add new fields, not overwrite existing ones
    auto update = make_document(kvp("$set", doc.view()));
    
    // Finally, we can perform the update operation using the update_one method of the collection object
    try {
        auto result = collection.update_one(make_document(kvp("_id", id)), update.view());
        if (result) {
            ofLogVerbose("ofxMongoDB::add_fields_to_entry_from_Json") << "Successfully added new fields to entry with ID: " << id_str << std::endl;
        } else {
            ofLogError("ofxMongoDB::add_fields_to_entry_from_Json") << "Error adding new fields to entry with ID: " << id_str << std::endl;
        }
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::add_fields_to_entry_from_Json") << "Error adding new fields to entry: " << e.what() << std::endl;
    }
    
}

void ofxMongoDB::insert_json_into_DB(const ofJson& json) {
    try {
        // Convert the ofJson object to a BSON document
        std::string json_str = json.dump();
        bsoncxx::document::value doc = bsoncxx::from_json(json_str);
        // Insert the document into the collection
        collection.insert_one(doc.view());
    } catch (const mongocxx::exception& e) {
        ofLogError("ofxMongoDB::insert_json_into_DB") << "Error: " << e.what() << std::endl;
    }
}

