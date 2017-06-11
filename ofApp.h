#pragma once

#include "ofMain.h"
#include "ofxDirectShowPlayer.h"
#include "ofxCv.h"	// oF0.9.8—p
#include "ofxOpenCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxDirectShowPlayer movie;
		ofTexture tex;
		int movie_width, movie_height;

		cv::Mat src_img;
		cv::Mat gray_img; 
		cv::Mat bg_img;
		cv::Mat sub_img;
		cv::Mat binary_img;
		ofImage result_ofImage;
		bool grabBG;

		// GUI
		ofxPanel gui;
		ofParameterGroup gui_params;
		ofParameter<int> binarize_threshold;
		bool showGui;
};
