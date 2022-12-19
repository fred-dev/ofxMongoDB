#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myDatabase.setup("mongodb+srv://fred-mongodb:EKoB3RJuVNxahVIm@audioweather-mongodb.7vs4f.mongodb.net/?retryWrites=true&w=majority", "audioweather", "audioWeatherAll");

    myDatabase.connect();
    
   

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
    if(key == 'p'){
        ofJson databaseAsJson;
        
        databaseAsJson = myDatabase.getDatabaseAsJSON();
        
        cout<< ofToString(databaseAsJson);
    }
    if (key == 'u') {
        myDatabase.updateDocument();
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
