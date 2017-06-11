#include "ofApp.h"

using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
	movie.load("movies/07.mp4");
	movie.play();

	//ofImage temp;
	//temp.allocate(movie.getWidth(), movie.getHeight(), OF_IMAGE_COLOR_ALPHA);
	//temp.setColor(0);

	movie_width = movie.getWidth();
	movie_height = movie.getHeight();

	tex.allocate(movie_width, movie_height, GL_RGBA);
	//tex.loadData(temp.getPixels());

	src_img = Mat(movie_width, movie_height, CV_8UC3);
	gray_img = Mat(movie_width, movie_height, CV_8UC1);
	bg_img = Mat(movie_width, movie_height, CV_8UC1);
	sub_img = Mat(movie_width, movie_height, CV_8UC1);
	binary_img = Mat(movie_width, movie_height, CV_8UC1);

	// GUI
	gui_params.setName("tracking");
	gui_params.add(binarize_threshold.set("binarize", 128, 0, 255));

	string gui_settings = "settings";
	gui.setName(gui_settings);
	gui.setup(gui_params);
	gui.loadFromFile(gui_settings + ".xml");
	showGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	movie.update();

	movie.update();
	tex.loadData(movie.getPixels());

	// copy to cv
	src_img.data = movie.getPixels().getData();
	cvtColor(src_img, gray_img, CV_BGR2GRAY);

	// grab bg image
	if (grabBG)
	{
		bg_img = gray_img.clone();
		grabBG = false;
	}

	// subtraction
	sub_img = -gray_img + bg_img;

	// binarize
	threshold(sub_img, binary_img, binarize_threshold, 255, THRESH_BINARY);

	// copy to ofImage
	result_ofImage.setFromPixels(binary_img.data, movie_width, movie_height, OF_IMAGE_GRAYSCALE);
	result_ofImage.update();


	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
	//if (tex.isAllocated() || tex.isAllocated()) {
	//	tex.draw(0, 0);
	//}

	result_ofImage.draw(0, 0);

	if (showGui)
	{
		if (tex.isAllocated() || tex.isAllocated()) {
			tex.draw(0, 0, 320, 240);
		}
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key)
	{
	case 'b':
		grabBG = !grabBG;
		break;

	case 'f':
		ofToggleFullscreen();
		break;

	case 'g':
		showGui = !showGui;
		break;

	default:
		break;
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
