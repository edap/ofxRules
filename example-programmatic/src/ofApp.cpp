#include "ofApp.h"

namespace itg
{
    //--------------------------------------------------------------
    void ofApp::setup()
    {
        ofSetFrameRate(60);
        ofBackground(0);
        
        cam.setNearClip(1e-2);
        cam.setFarClip(1e4);
        cam.setDistance(80);
        cam.lookAt(ofVec3f(0, 20, 0));
       
        rules.setMaxDepth(300);
        rules.getMeshRef().setMode(OF_PRIMITIVE_LINES);
        
        {
            Rule::Ptr rule = rules.addRule("test", 100);
            
            LineAction::Ptr action = rule->addAction<LineAction>("test");
            action->translate(0, 0.1, 0);
            action->rotate(1, 0, 0);
            action->setNextRuleName("test");
        }
       
        {
            Rule::Ptr rule = rules.addRule("test", 100);
            
            LineAction::Ptr action = rule->addAction<LineAction>("test");
            action->translate(0, 0.1, 0);
            action->rotate(0, 20, 0);
            action->setNextRuleName("test");
        }
        
        {
            Rule::Ptr rule = rules.addRule("test", 100);
            
            LineAction::Ptr action = rule->addAction<LineAction>("test");
            action->translate(0, 0.4, 0);
            action->rotate(1, 0, -2);
            action->setNextRuleName("test");
        }
        
        {
            Rule::Ptr rule = rules.addRule("test", 6);
            
            TransformAction::Ptr left = rule->addAction<TransformAction>("test");
            left->rotate(0, 180, 0);
            left->setNextRuleName("test");
            
            TransformAction::Ptr right = rule->addAction<TransformAction>("test");
            right->rotate(15, 0, 0);
            right->setNextRuleName("test");
        }
        
        rules.setStartRule("test");
        rules.start();
    }

    //--------------------------------------------------------------
    void ofApp::update()
    {
        ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
        
        rules.step();
    }

    //--------------------------------------------------------------
    void ofApp::draw()
    {
        cam.begin();
        rules.draw();
        cam.end();
    }
    
    //--------------------------------------------------------------
    void ofApp::keyPressed(int key){

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
    void ofApp::windowResized(int w, int h){

    }

    //--------------------------------------------------------------
    void ofApp::gotMessage(ofMessage msg){

    }

    //--------------------------------------------------------------
    void ofApp::dragEvent(ofDragInfo dragInfo){

    }
}
