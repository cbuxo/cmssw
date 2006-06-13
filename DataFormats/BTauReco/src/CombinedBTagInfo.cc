// -*- C++ -*-
//
// Package:    CombinedBTagInfo
// Class:      CombinedBTagInfo
// 
/**\class CombinedBTagInfo CombinedBTagInfo.cc DataFormats/BTauReco/src/CombinedBTagInfo.cc

 Description: Extended information for combined b-jet tagging

 Implementation:
     <Notes on implementation>
*/


// this class header

#include "DataFormats/BTauReco/interface/CombinedBTagInfo.h"

//------------------------------------------------------------------------------
// Constructors
//------------------------------------------------------------------------------
reco::CombinedBTagInfo::CombinedBTagInfo() {

  // reset everything
  reco::CombinedBTagInfo::reset();

  // fill map with string name of tagging variable
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::Category]                        = "Category";
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::VertexMass]                      = "VertexMass";
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::VertexMultiplicity]              = "VertexMultiplicity";
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::FlightDistance2DSignificance]    = "FlightDistance2DSignificance";
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::ESVXOverE]                       = "ESVXOverE";
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::TrackRapidity]                   = "TrackRapidity";
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::TrackIP2DSignificance]           = "TrackIP2DSignificance";
  reco::CombinedBTagInfo::taggingVarName_[reco::CombinedBTagInfo::TrackIP2DSignificanceAboveCharm] = "TrackIP2DSignificanceAboveCharm";
  
} // constructor


//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
reco::CombinedBTagInfo::~CombinedBTagInfo() {

}


// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------

//
// map related
//

std::string reco::CombinedBTagInfo::getTaggingVarName(reco::CombinedBTagInfo::TaggingVariable taggingVar) {

  std::map <reco::CombinedBTagInfo::TaggingVariable, std::string>::const_iterator iter;
  iter = reco::CombinedBTagInfo::taggingVarName_.find(taggingVar);

  if (iter != reco::CombinedBTagInfo::taggingVarName_.end())
    return reco::CombinedBTagInfo::taggingVarName_[taggingVar];
  else
    return "notFound";
  

} // void printTaggingVarName

// -------------------------------------------------------------------------------
bool reco::CombinedBTagInfo::existTrackData(reco::TrackRef trackRef) {

  bool returnValue = false;

  reco::CombinedBTagInfo::TrackDataAssociation::const_iterator iter;
  iter = reco::CombinedBTagInfo::trackDataMap_.find(trackRef);
  if (iter != reco::CombinedBTagInfo::trackDataMap_.end()) {
    returnValue = true;
  }
  
  return returnValue;

} // bool exitTrackData
// -------------------------------------------------------------------------------

void reco::CombinedBTagInfo::flushTrackData() {

  //  reco::CombinedBTagInfo::trackDataMap_.clear();
  
} // void flushTrackData
// -------------------------------------------------------------------------------

void reco::CombinedBTagInfo::storeTrackData(reco::TrackRef trackRef,
					    const reco::CombinedBTagInfo::TrackData& trackData) {
  
  //  std::cout << "*** trackData to store " << std::endl;
  //  trackData.print();

  reco::CombinedBTagInfo::trackDataMap_.insert(trackRef, trackData);

//   reco::CombinedBTagInfo::TrackDataAssociation::const_iterator iter;
//   iter = reco::CombinedBTagInfo::trackDataMap_.find(trackRef);
//   if (iter != reco::CombinedBTagInfo::trackDataMap_.end())
//     (iter->val).print();

} //void storeTrackData
// -------------------------------------------------------------------------------

int reco::CombinedBTagInfo::sizeTrackData() {
  
  int size = reco::CombinedBTagInfo::trackDataMap_.size();

  return size;

} // int sizeTrackData
// -------------------------------------------------------------------------------

const reco::CombinedBTagInfo::TrackData* reco::CombinedBTagInfo::getTrackData(reco::TrackRef trackRef) {

 reco::CombinedBTagInfo::TrackDataAssociation::const_iterator iter;

 iter = reco::CombinedBTagInfo::trackDataMap_.find(trackRef);

 if (iter != reco::CombinedBTagInfo::trackDataMap_.end()) {

   return &(iter->val);

 } else {

   return 0;

 } //if iter != end

} // TrackData* getTrackData
// -------------------------------------------------------------------------------
void reco::CombinedBTagInfo::printTrackData() {

  reco::CombinedBTagInfo::TrackDataAssociation::const_iterator mapIter;
  reco::CombinedBTagInfo::TrackDataAssociation::const_iterator mapBegin = reco::CombinedBTagInfo::trackDataMap_.begin();
  reco::CombinedBTagInfo::TrackDataAssociation::const_iterator mapEnd   = reco::CombinedBTagInfo::trackDataMap_.end();

  for (mapIter = mapBegin; mapIter != mapEnd; mapIter++) {

    const reco::CombinedBTagInfo::TrackData& trackData = mapIter->val;
    trackData.print();


  } // for mapIter
  
} // void printTrackData
// -------------------------------------------------------------------------------

bool reco::CombinedBTagInfo::existVertexData(std::vector<reco::Vertex>::const_iterator vertexRef) {

  bool returnValue = false;

  std::map <std::vector<reco::Vertex>::const_iterator, reco::CombinedBTagInfo::VertexData>::const_iterator iter;

  // try to find element
  iter = reco::CombinedBTagInfo::vertexDataMap_.find(vertexRef);
  if (iter != reco::CombinedBTagInfo::vertexDataMap_.end())
    returnValue = true;

  return returnValue;

} // bool exitVertexData
// -------------------------------------------------------------------------------

void reco::CombinedBTagInfo::flushVertexData() {
  //  reco::CombinedBTagInfo::vertexDataMap_.clear();
  
} // void flushVertexData
// -------------------------------------------------------------------------------

void reco::CombinedBTagInfo::storeVertexData(std::vector<reco::Vertex>::const_iterator vertexRef,
					     const reco::CombinedBTagInfo::VertexData& vertexData) {
  
  reco::CombinedBTagInfo::vertexDataMap_[vertexRef] = vertexData;

} //void storeVertexData
// -------------------------------------------------------------------------------

int reco::CombinedBTagInfo::sizeVertexData() {
  
  int size = reco::CombinedBTagInfo::vertexDataMap_.size();

  return size;

} // int sizeVertexData
// -------------------------------------------------------------------------------

reco::CombinedBTagInfo::VertexData* reco::CombinedBTagInfo::getVertexData(std::vector<reco::Vertex>::const_iterator vertexRef) {

  std::map <std::vector<reco::Vertex>::const_iterator, reco::CombinedBTagInfo::VertexData>::const_iterator iter;

  // try to find element
  iter = reco::CombinedBTagInfo::vertexDataMap_.find(vertexRef);

  if (iter != reco::CombinedBTagInfo::vertexDataMap_.end()) {

    // found element
    return &reco::CombinedBTagInfo::vertexDataMap_[vertexRef];

  } else {
    
    // element not found
    return 0;

  } //if iter != end

} // VertexData* getVertexData
// -------------------------------------------------------------------------------
void reco::CombinedBTagInfo::reset() {

  //
  // reset all information
  //
  GlobalVector resetVector (-999.0,-999.0,-999.0);

  // flush maps and vectors
  reco::CombinedBTagInfo::flushTrackData();
  reco::CombinedBTagInfo::flushVertexData();
  reco::CombinedBTagInfo::secondaryVertices_.clear();
  reco::CombinedBTagInfo::tracksAboveCharm_.clear();
  reco::CombinedBTagInfo::tracksAtSecondaryVertex_.clear();
  
  // reset variables
  reco::CombinedBTagInfo::vertexType_                       = reco::CombinedBTagInfo::NotDefined;
						            
  reco::CombinedBTagInfo::jetPt_                            = -999;
  reco::CombinedBTagInfo::jetEta_                           = -999;
  				
  reco::CombinedBTagInfo::pB_                               = resetVector;
  reco::CombinedBTagInfo::pAll_                             = resetVector;   
  reco::CombinedBTagInfo::bPLong_                           = -999;
  reco::CombinedBTagInfo::bPt_                              = -999;
  reco::CombinedBTagInfo::vertexMass_                       = -999;
  reco::CombinedBTagInfo::vertexMultiplicity_               = -999;
  reco::CombinedBTagInfo::eSVXOverE_                        = -999;
  reco::CombinedBTagInfo::meanTrackY_                       = -999;
  
  reco::CombinedBTagInfo::energyBTracks_                    = -999;
  reco::CombinedBTagInfo::energyAllTracks_                  = -999;
  						            
  reco::CombinedBTagInfo::angleGeomKinJet_                  = -999;
  reco::CombinedBTagInfo::angleGeomKinVertex_               = -999;  

  reco::CombinedBTagInfo::flightDistance2DMin_              = -999;
  reco::CombinedBTagInfo::flightDistanceSignificance2DMin_  = -999;
  reco::CombinedBTagInfo::flightDistance3DMin_              = -999;
  reco::CombinedBTagInfo::flightDistanceSignificance3DMin_  = -999;

  reco::CombinedBTagInfo::flightDistance2DMax_              = -999;
  reco::CombinedBTagInfo::flightDistanceSignificance2DMax_  = -999;
  reco::CombinedBTagInfo::flightDistance3DMax_              = -999;
  reco::CombinedBTagInfo::flightDistanceSignificance3DMax_  = -999;

  reco::CombinedBTagInfo::flightDistance2DMean_             = -999;
  reco::CombinedBTagInfo::flightDistanceSignificance2DMean_ = -999;
  reco::CombinedBTagInfo::flightDistance3DMean_             = -999;
  reco::CombinedBTagInfo::flightDistanceSignificance3DMean_ = -999;

  reco::CombinedBTagInfo::first2DSignedIPSigniAboveCut_     = -999;
  
} //reset

// -------------------------------------------------------------------------------
