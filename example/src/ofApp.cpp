#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	myDatabase.setup("URL", "Collection", "Databse");
	
    myDatabase.connect();
    
    ofJson jsonFile;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::exit(){
    myDatabase.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'p') {
		ofJson allRecordsAsJSON;
		allRecordsAsJSON = myDatabase.getAllRecordsAsJSON();
		ofSavePrettyJson("allRecordsAsJSON.json", allRecordsAsJSON);
	}

	if (key == 'u') {
		myDatabase.updateRecord("fieldName", "New field value", "object ID");
	}

	if (key == 'f') {
		ofJson filteredRecordsAsJSON;
		filteredRecordsAsJSON = myDatabase.getFilteredRecordsAsJSON("fieldName", "Filter Field value");
		ofSavePrettyJson("filteredRecordsAsJSON.json", filteredRecordsAsJSON);
	}

	if (key == 'v') {
		ofJson filteredRecordRangeAsJSON;
		filteredRecordRangeAsJSON = myDatabase.getFilteredRecordsAsJSON("fieldName", 0, 1000);
		ofSavePrettyJson("filteredRecordRangeAsJSON.json", filteredRecordRangeAsJSON);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
