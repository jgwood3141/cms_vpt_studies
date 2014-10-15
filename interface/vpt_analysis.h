// John Wood
// UVa HEP
// VPT Test Rig
//
// Header File
// vpt_analysis.h

#include "TROOT.h"
#include "TStyle.h"
#include "TObject.h"
#include "Riostream.h"
#include "TFile.h"
#include "TTree.h"
#include "TTreeFormula.h"
#include "TBranch.h"
#include "TF1.h"
#include "TString.h"
#include "TCanvas.h"
#include "TMultiGraph.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TAxis.h"
#include "TMarker.h"
#include "TAttMarker.h"
#include "TLegend.h"
#include "TPave.h"
#include "TPaveText.h"
#include "TPaveStats.h"
#include "TLatex.h"

#include <algorithm>
#include <deque>
#include <utility>
#include <vector>
#include "math.h"



//=============================================================================
// 
// Namespaces and Enums
//
//=============================================================================

namespace analysis_type{ enum analysis_type{ analyze, plot, fit }; }
namespace site{ enum site{ uva, brunel }; }
namespace run_num{ enum run_num{ run1, run2, run3, run4, run5, run6 }; }

//=============================================================================
// 
// Utility Class for VPT info
//
//=============================================================================

struct measurement{

  // general measurement info
  Float_t angle_; 
  Float_t date_;
  Float_t date_temp_;
  Float_t time_;
  Float_t time_temp_;
  Float_t elapsed_time_;
  Float_t elapsed_time_temp_;
  Float_t integrated_charge_;
  Float_t integrated_charge_err_;
  Float_t incremental_charge_;
  Float_t rie_number_float_;
  Int_t   relative_err_filter_;
 
  // blue reference led info
  Int_t   blue_reference_spike_filter_;
  Float_t blue_reference_anode_; 
  Float_t blue_reference_anode_err_;
  Float_t blue_reference_anode_raw_; 
  Float_t blue_reference_anode_raw_std_dev_;
  Float_t blue_reference_anode_raw_err_;
  Float_t blue_reference_cathode_current_; 
  Float_t blue_reference_cathode_current_std_dev_;
  Float_t blue_reference_cathode_current_err_;
  Float_t blue_reference_led_frequency_;
  Float_t blue_reference_led_voltage_;
  Float_t blue_reference_pin_; 
  Float_t blue_reference_pin_std_dev_; 
  Float_t blue_reference_pin_err_; 
  Float_t blue_reference_pin_correction_; 
  Float_t blue_reference_pin_correction_err_; 
  Float_t blue_reference_vpt_div_pin_; 
  Float_t blue_reference_vpt_div_pin_NIM_corrected_; 

  // blue load led info
  Float_t blue_load_anode_; 
  Float_t blue_load_anode_err_; 
  Float_t blue_load_anode_raw_; 
  Float_t blue_load_anode_raw_std_dev_;
  Float_t blue_load_anode_raw_err_; 
  Float_t blue_load_dark_cathode_current_; 
  Float_t blue_load_dark_cathode_current_std_dev_;
  Float_t blue_load_dark_cathode_current_err_;
  Float_t blue_load_cathode_current_; 
  Float_t blue_load_cathode_current_std_dev_;
  Float_t blue_load_cathode_current_err_;
  Float_t blue_load_cathode_current_per_pulse_; 
  Float_t blue_load_cathode_current_per_pulse_std_dev_;
  Float_t blue_load_cathode_current_per_pulse_err_;
  Float_t blue_load_cathode_current_raw_; 
  Float_t blue_load_cathode_current_raw_std_dev_;
  Float_t blue_load_cathode_current_raw_err_;
  Float_t blue_load_led_frequency_;
  Float_t blue_load_led_isOn_;
  Float_t blue_load_led_voltage_;
  Float_t blue_load_pin_; 
  Float_t blue_load_pin_std_dev_;
  Float_t blue_load_pin_err_;
  Float_t blue_load_pin_correction_;
  Float_t blue_load_pin_correction_err_;

  // blue soak led info -- Not used, but still in data file
  Float_t blue_soak_anode_raw_; 
  Float_t blue_soak_anode_raw_std_dev_;
  Float_t blue_soak_anode_raw_err_;
  Float_t blue_soak_led_frequency_;
  Float_t blue_soak_led_isOn_;
  Float_t blue_soak_led_voltage_;
  Float_t blue_soak_pin_; 
  Float_t blue_soak_pin_std_dev_; 
  Float_t blue_soak_pin_err_; 
  
  // orange reference led info
  Int_t   orange_reference_spike_filter_;
  Float_t orange_reference_anode_; 
  Float_t orange_reference_anode_err_;
  Float_t orange_reference_anode_raw_; 
  Float_t orange_reference_anode_raw_std_dev_;
  Float_t orange_reference_anode_raw_err_;
  Float_t orange_reference_cathode_current_; 
  Float_t orange_reference_cathode_current_std_dev_;
  Float_t orange_reference_cathode_current_err_;
  Float_t orange_reference_led_frequency_;
  Float_t orange_reference_pin_; 
  Float_t orange_reference_pin_std_dev_;
  Float_t orange_reference_pin_err_;
  Float_t orange_reference_pin_correction_;
  Float_t orange_reference_pin_correction_err_;

  // interesting quantities
  Float_t blue_div_orange_reference_anode_;
  Float_t blue_div_orange_reference_anode_err_;
  Float_t blue_div_orange_reference_pin_;
  Float_t blue_div_orange_reference_pin_err_;
  Float_t gain_;
  Float_t gain_err_;

  // amplifier pulsing info 
  Float_t amp_pin_in_; 
  Float_t amp_pin_in_std_dev_;
  Float_t amp_pin_in_err_;
  Float_t amp_pin_out_; 
  Float_t amp_pin_out_std_dev_;
  Float_t amp_pin_out_err_;
  Float_t amp_vpt_in_; 
  Float_t amp_vpt_in_std_dev_;
  Float_t amp_vpt_in_err_;
  Float_t amp_vpt_out_; 
  Float_t amp_vpt_out_std_dev_; 
  Float_t amp_vpt_out_err_; 

  // environmental information
  Float_t temperature_; 
  Float_t temperature_std_dev_;
  Float_t temperature_err_;
  Float_t temperature_vpt_;
  Float_t temperature_pa_;
  Float_t temperature_sa_; 
  Float_t temperature_led_; 
  Float_t temperature_lab_;
  Float_t humidity_; 
  Float_t humidity_std_dev_; 
  Float_t humidity_err_;

};

//_____________________________________________________________________________
//
// Initialization function for measurement structure
//
void initialize(measurement &evt){
  
  // general measurement info
  evt.rie_number_float_       = -99.9;
  evt.date_                   = -99.9;
  evt.date_temp_              = -99.9;
  evt.time_                   = -99.9;
  evt.time_temp_              = -99.9;
  evt.elapsed_time_           = -99.9;
  evt.elapsed_time_temp_      = -99.9;
  evt.integrated_charge_      = -99.9;
  evt.integrated_charge_err_  = -99.9;
  evt.incremental_charge_     = -99.9;
  evt.angle_                  = -99.9; 
  evt.relative_err_filter_    = 1;

  // blue reference led info
  evt.blue_reference_spike_filter_              = 1;
  evt.blue_reference_anode_                     = -99.9; 
  evt.blue_reference_anode_err_                 = -99.9;
  evt.blue_reference_anode_raw_                 = -99.9; 
  evt.blue_reference_anode_raw_std_dev_         = -99.9;
  evt.blue_reference_anode_raw_err_             = -99.9;
  evt.blue_reference_cathode_current_           = -99.9; 
  evt.blue_reference_cathode_current_std_dev_   = -99.9;
  evt.blue_reference_cathode_current_err_       = -99.9;
  evt.blue_reference_led_frequency_             = -99.9;
  evt.blue_reference_led_voltage_               = -99.9;
  evt.blue_reference_pin_                       = -99.9; 
  evt.blue_reference_pin_std_dev_               = -99.9; 
  evt.blue_reference_pin_err_                   = -99.9; 
  evt.blue_reference_pin_correction_            = -99.9;
  evt.blue_reference_pin_correction_err_        = -99.9;
  evt.blue_reference_vpt_div_pin_               = -99.9; 
  evt.blue_reference_vpt_div_pin_NIM_corrected_ = -99.9; 

  // blue load led info
  evt.blue_load_anode_                             = -99.9; 
  evt.blue_load_anode_err_                         = -99.9; 
  evt.blue_load_anode_raw_                         = -99.9; 
  evt.blue_load_anode_raw_std_dev_                 = -99.9;
  evt.blue_load_anode_raw_err_                     = -99.9; 
  evt.blue_load_dark_cathode_current_              = -99.9; 
  evt.blue_load_dark_cathode_current_std_dev_      = -99.9;
  evt.blue_load_dark_cathode_current_err_          = -99.9;
  evt.blue_load_cathode_current_                   = -99.9; 
  evt.blue_load_cathode_current_std_dev_           = -99.9;
  evt.blue_load_cathode_current_err_               = -99.9;
  evt.blue_load_cathode_current_per_pulse_         = -99.9; 
  evt.blue_load_cathode_current_per_pulse_std_dev_ = -99.9;
  evt.blue_load_cathode_current_per_pulse_err_     = -99.9;
  evt.blue_load_cathode_current_raw_               = -99.9; 
  evt.blue_load_cathode_current_raw_std_dev_       = -99.9;
  evt.blue_load_cathode_current_raw_err_           = -99.9;
  evt.blue_load_led_frequency_                     = -99.9;
  evt.blue_load_led_isOn_                          = -99.9;
  evt.blue_load_led_voltage_                       = -99.9;
  evt.blue_load_pin_                               = -99.9; 
  evt.blue_load_pin_std_dev_                       = -99.9;
  evt.blue_load_pin_err_                           = -99.9;
  evt.blue_load_pin_correction_                    = -99.9;
  evt.blue_load_pin_correction_err_                = -99.9;

  // blue soak led info -- Not used, but still in data file
  evt.blue_soak_anode_raw_         = -99.9; 
  evt.blue_soak_anode_raw_std_dev_ = -99.9;
  evt.blue_soak_anode_raw_err_     = -99.9;
  evt.blue_soak_led_frequency_     = -99.9;
  evt.blue_soak_led_isOn_          = -99.9;
  evt.blue_soak_led_voltage_       = -99.9;
  evt.blue_soak_pin_               = -99.9; 
  evt.blue_soak_pin_std_dev_       = -99.9; 
  evt.blue_soak_pin_err_           = -99.9; 

  // orange reference led info
  evt.orange_reference_spike_filter_            = 1;
  evt.orange_reference_anode_                   = -99.9; 
  evt.orange_reference_anode_err_               = -99.9;
  evt.orange_reference_anode_raw_               = -99.9; 
  evt.orange_reference_anode_raw_std_dev_       = -99.9;
  evt.orange_reference_anode_raw_err_           = -99.9;
  evt.orange_reference_cathode_current_         = -99.9; 
  evt.orange_reference_cathode_current_std_dev_ = -99.9;
  evt.orange_reference_cathode_current_err_     = -99.9;
  evt.orange_reference_led_frequency_           = -99.9;
  evt.orange_reference_pin_                     = -99.9; 
  evt.orange_reference_pin_std_dev_             = -99.9;
  evt.orange_reference_pin_err_                 = -99.9;
  evt.orange_reference_pin_correction_          = -99.9;
  evt.orange_reference_pin_correction_err_      = -99.9;

  // interesting quantities
  evt.blue_div_orange_reference_anode_     = -99.9;
  evt.blue_div_orange_reference_anode_err_ = -99.9;
  evt.blue_div_orange_reference_pin_       = -99.9;
  evt.blue_div_orange_reference_pin_err_   = -99.9;
  evt.gain_                                = -99.9;
  evt.gain_err_                            = -99.9;

  // amplifier pulsing info 
  evt.amp_pin_in_          = -99.9; 
  evt.amp_pin_in_std_dev_  = -99.9;
  evt.amp_pin_in_err_      = -99.9;
  evt.amp_pin_out_         = -99.9; 
  evt.amp_pin_out_std_dev_ = -99.9;
  evt.amp_pin_out_err_     = -99.9;
  evt.amp_vpt_in_          = -99.9; 
  evt.amp_vpt_in_std_dev_  = -99.9;
  evt.amp_vpt_in_err_      = -99.9;
  evt.amp_vpt_out_         = -99.9; 
  evt.amp_vpt_out_std_dev_ = -99.9; 
  evt.amp_vpt_out_err_     = -99.9; 

  // environmental information
  evt.temperature_         = -99.9; 
  evt.temperature_std_dev_ = -99.9;
  evt.temperature_err_     = -99.9;
  evt.temperature_vpt_     = -99.9;
  evt.temperature_pa_      = -99.9; 
  evt.temperature_sa_      = -99.9; 
  evt.temperature_led_     = -99.9; 
  evt.temperature_lab_     = -99.9; 
  evt.humidity_            = -99.9; 
  evt.humidity_std_dev_    = -99.9; 
  evt.humidity_err_        = -99.9;

  return;
}
  
//_____________________________________________________________________________
//
// vpt and run info
//
class vptInfo{

 public:
  
  site::site       site_;           // enum for run site
  run_num::run_num run_num_;        // enum for run number
  vector<TString>  friend_trees_;   // List of TTree names of friends
  TString          tree_name_;      // TTree name in root file
  TString          raw_data_file_;  // file and path to raw data 
  TString          rie_number_;     // manufacturer ID 
  Float_t          run_begin_;      // UVa has stability data in raw files
  Color_t          color_;          // color to draw variables from this data file
  
  TF1 *fit_blue_;
  TF1 *fit_blue_norm_;
  TF1 *fit_orng_;
  TF1 *fit_orng_norm_;


  // Contrunctor and destructor
  vptInfo(): rie_number_(-99){};
  vptInfo(site::site run_site, run_num::run_num run, TString vpt_num, double run_begin, vector<TString> friend_trees, Color_t color=kBlue);
  virtual ~vptInfo();

  // class functions
  void get_offset_corrections(measurement &evt);
  
};

typedef std::pair< vptInfo*, TGraphErrors* >               vpt_plot;
typedef std::vector< std::pair< vptInfo*, TGraphErrors* > > v_vpt_plot;

//_____________________________________________________________________________
//
// Constructor for vptInfo class
//
vptInfo::vptInfo(site::site run_site, run_num::run_num run, TString vpt_num, double run_begin, vector<TString> friend_trees, Color_t color){

  // 
  // Set-up generic information for this vpt
  //
  site_         = run_site;
  run_num_      = run;
  rie_number_   = vpt_num;
  run_begin_    = run_begin;
  friend_trees_ = friend_trees;
  color_        = color;
  
  fit_blue_      = NULL;
  fit_blue_norm_ = NULL;
  fit_orng_      = NULL;
  fit_orng_norm_ = NULL;


  //
  // Set-up useful strings for file i/o
  //
  TString site_str = "";
  if( run_site == site::uva ) site_str += "uva_";
  else                        site_str += "brunel_";

  TString run_str = "";
  if(run==run_num::run1) run_str += "run1_";
  if(run==run_num::run2) run_str += "run2_";
  if(run==run_num::run3) run_str += "run3_";
  if(run==run_num::run4) run_str += "run4_";
  if(run==run_num::run5) run_str += "run5_";
  if(run==run_num::run6) run_str += "run6_";
  
  //
  // Set-up for grabbing the raw data for this vpt
  //
  TString raw_file = "../data/rawData_";
  raw_file += site_str;
  raw_file += run_str;
  raw_file += "vpt";
  raw_file += vpt_num;
  raw_file += ".dat";
  
  raw_data_file_ = raw_file;
  
  
  // 
  // Set-up TTree name for this vpt
  //
  TString tree_name = site_str + run_str;
  tree_name        +="vpt";
  tree_name        += vpt_num;
  
  tree_name_  = tree_name;
  
      
}

//_____________________________________________________________________________
//
// vptInfo Destructor
//
vptInfo::~vptInfo(){

  cout << "Destroying VPT!" << endl;

}

//_____________________________________________________________________________
//
// List of offset corrections for each vpt
//
void vptInfo::get_offset_corrections(measurement &evt){

  //
  // Corrections for UVa Site
  //
  if(site_==site::uva){

    //
    // Corrections for Run2
    //
    if(run_num_==run_num::run2){

      if(rie_number_=="7095"){
        if(evt.elapsed_time_>3062 && evt.elapsed_time_<3246.8){    // Switched Reference <-> Soak LED due to Reference LED instability
	  evt.blue_reference_anode_raw_ += 0.46e-9;
          evt.blue_reference_pin_       += 0.41e-9;
        }
        if(evt.elapsed_time_>3246.8 && evt.elapsed_time_<3327.9){  // Reset system after setting external triggering, offset after restart
          evt.blue_reference_anode_raw_ += 0.540e-9;
          evt.blue_reference_pin_       += 0.465e-9;
        }
        if(evt.elapsed_time_>3327.9){                              // Removed Black Plastic wrap for Humidity, ambient light levels higher
          evt.blue_reference_anode_raw_ += 0.455e-9;
          evt.blue_reference_pin_       += 0.402e-9;
        }
      }
      if(rie_number_=="7182"){
        if(evt.elapsed_time_>3062 && evt.elapsed_time_<3246.8){
          evt.blue_reference_anode_raw_ += -0.17e-9;
          evt.blue_reference_pin_       += -0.025e-9;
        }
        if(evt.elapsed_time_>3246.8 && evt.elapsed_time_<3327.9){
          evt.blue_reference_anode_raw_ += 0.00e-9;
          evt.blue_reference_pin_       += 0.085e-9;
        }
        if(evt.elapsed_time_>3327.9){
          evt.blue_reference_anode_raw_ += -0.165e-9;
          evt.blue_reference_pin_       += -0.033e-9;
        }
      }
      if(rie_number_=="7112"){
        if(evt.elapsed_time_>3062 && evt.elapsed_time_<3246.8){
          evt.blue_reference_anode_raw_ += -0.285e-9;
          evt.blue_reference_pin_       += -0.18e-9;
        }
        if(evt.elapsed_time_>3246.8 && evt.elapsed_time_<3327.9){
          evt.blue_reference_anode_raw_ += -0.185e-9;
          evt.blue_reference_pin_       += -0.075e-9;
        }
        if(evt.elapsed_time_>3327.9){
          evt.blue_reference_anode_raw_ += -0.300e-9;
          evt.blue_reference_pin_       += -0.195e-9;
        }
      }
      if(rie_number_=="7120"){
        if(evt.elapsed_time_>3062 && evt.elapsed_time_<3246.8){
          evt.blue_reference_anode_raw_ += 0.04e-9;
          evt.blue_reference_pin_       += -0.06e-9;
        }
        if(evt.elapsed_time_>3246.8 && evt.elapsed_time_<3327.9){
          evt.blue_reference_anode_raw_ += 0.095e-9;
          evt.blue_reference_pin_       += -0.015e-9;
        }
        if(evt.elapsed_time_>3327.9){
          evt.blue_reference_anode_raw_ += 0.038e-9;
          evt.blue_reference_pin_       += -0.0625e-9;
        }
      }
      if(rie_number_=="7099"){
        if(evt.elapsed_time_>3062 && evt.elapsed_time_<3246.8){
          evt.blue_reference_anode_raw_ += 0.245e-9;
          evt.blue_reference_pin_       += 0;
        }
        if(evt.elapsed_time_>3246.8 && evt.elapsed_time_<3327.9){
          evt.blue_reference_anode_raw_ += 0.295e-9;
          evt.blue_reference_pin_       += 0.00e-9;
        }
        if(evt.elapsed_time_>3327.9){
          evt.blue_reference_anode_raw_ += 0.242e-9;
          evt.blue_reference_pin_       += 0.0e-9;
        }
      }

    } // end if UVa, Run2


    //
    // Corrections for Run3
    //
    if(run_num_ == run_num::run3){

      if(rie_number_=="13047"){
        if(evt.elapsed_time_>522 && evt.elapsed_time_<690){
	  evt.blue_load_pin_        -= 0.050e-9;
          evt.blue_reference_pin_   -= 0.030e-9;
	  evt.orange_reference_pin_ -= 0.1185e-9;
	}
        if(evt.elapsed_time_>1164 && evt.elapsed_time_<1225){
	  evt.blue_load_pin_        -= 0.050e-9;
	  evt.blue_reference_pin_   -= 0.025e-9;
	  evt.orange_reference_pin_ -= 0.1185e-9;
	}
        if(evt.elapsed_time_>1225 && evt.elapsed_time_<1335){
	  evt.blue_load_pin_        -= 0.02750e-9;
	  evt.blue_reference_pin_   -= 0.015e-9;
          evt.orange_reference_pin_ -= 0.07e-9;
	}
        if(evt.elapsed_time_>1335 && evt.elapsed_time_<1400){
	  evt.blue_load_pin_        += 0.0220e-9;
          evt.blue_reference_pin_   += 0.010e-9;
          evt.orange_reference_pin_ += 0.026e-9;
        }
      }

    } // end if UVa, Run3 


    //
    // Corrections for Run4
    //
    if(run_num_ == run_num::run4){
 
      // fix offset caused by shutdown from wire cutters flying into bore
      //  as well as many storms causing power outages to building
      if(rie_number_=="14649"){
	if(evt.elapsed_time_>186.25 && evt.elapsed_time_<200.25){
	  evt.blue_reference_anode_raw_   -= 0.5e-9;
          evt.blue_reference_pin_         -= 0.21e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       += 0.0e-9;
        }
	if(evt.elapsed_time_>215 && evt.elapsed_time_<264){
	  evt.blue_reference_anode_raw_   -= 0.0e-9;
          evt.blue_reference_pin_         -= 0.03e-9;
          evt.orange_reference_anode_raw_ -= 0.12e-9;
          evt.orange_reference_pin_       -= 0.54e-9;
        }
	if(evt.elapsed_time_>264 && evt.elapsed_time_<340.25){
	  evt.blue_reference_anode_raw_   += 0.14e-9;
          evt.blue_reference_pin_         += 0.03e-9;
          evt.orange_reference_anode_raw_ -= 0.06e-9;
          evt.orange_reference_pin_       -= 0.58e-9;
        }
	if(evt.elapsed_time_>340.25 && evt.elapsed_time_<359){
	  evt.blue_reference_anode_raw_   += 0.10e-9;
          evt.blue_reference_pin_         += 0.01e-9;
          evt.orange_reference_anode_raw_ -= 0.08e-9;
          evt.orange_reference_pin_       -= 1.25e-9;
        }
	if(evt.elapsed_time_>359 && evt.elapsed_time_<384){
	  evt.blue_reference_anode_raw_   -= 0.2e-9;
          evt.blue_reference_pin_         -= 0.05e-9;
          evt.orange_reference_anode_raw_ -= 0.32e-9;
          evt.orange_reference_pin_       -= 0.90e-9;
        }
	if(evt.elapsed_time_>384 && evt.elapsed_time_<465.5){
	  evt.blue_reference_anode_raw_   += 0.05e-9;
          evt.blue_reference_pin_         -= 0.03e-9;
          evt.orange_reference_anode_raw_ -= 0.16e-9;
          evt.orange_reference_pin_       -= 0.85e-9;
        }
	if(evt.elapsed_time_>465.5 && evt.elapsed_time_<530.8){
	  evt.blue_reference_anode_raw_   -= 0.4e-9;
          evt.blue_reference_pin_         -= 0.23e-9;
          evt.orange_reference_anode_raw_ -= 0.16e-9;
          evt.orange_reference_pin_       -= 0.86e-9;
        }
	if(evt.elapsed_time_>530.8 && evt.elapsed_time_<537.5){
	  evt.blue_reference_anode_raw_   += 0.015e-9;
          evt.blue_reference_pin_         -= 0.03e-9;
          evt.orange_reference_anode_raw_ -= 0.15e-9;
          evt.orange_reference_pin_       -= 0.85e-9;
        }
	if(evt.elapsed_time_>537.5 && evt.elapsed_time_<557.75){
	  evt.blue_reference_anode_raw_   -= 0.40e-9;
          evt.blue_reference_pin_         -= 0.23e-9;
          evt.orange_reference_anode_raw_ -= 0.14e-9;
          evt.orange_reference_pin_       -= 0.85e-9;
        }
	if(evt.elapsed_time_>557.75 && evt.elapsed_time_<850){
	  evt.blue_reference_anode_raw_   += 0.04e-9;
          evt.blue_reference_pin_         -= 0.02e-9;
          evt.orange_reference_anode_raw_ -= 0.14e-9;
          evt.orange_reference_pin_       -= 0.80e-9;
        }
	if(evt.elapsed_time_>850 && evt.elapsed_time_<1450){
	  evt.blue_reference_anode_raw_   += 0.12e-9;
          evt.blue_reference_pin_         += 0.18e-9;
          evt.orange_reference_anode_raw_ -= 0.31e-9;
          evt.orange_reference_pin_       -= 0.02e-9;
        }
	if(evt.elapsed_time_>1450){
	  evt.orange_reference_anode_raw_ -= 0.33e-9;
          evt.orange_reference_pin_       -= 0.02e-9;
	}
	if(evt.elapsed_time_>1450 && evt.elapsed_time_<1543.5){
	  evt.blue_reference_anode_raw_   -= 0.87e-9;
          evt.blue_reference_pin_         -= 0.20e-9;
	}
        if(evt.elapsed_time_>1543.5 && evt.elapsed_time_<1805.2){
	  evt.blue_reference_anode_raw_   -= 1.20e-9;
	  if(evt.elapsed_time_>1740){
	    evt.blue_reference_anode_raw_ -= 0.035e-9;
	  }
	  evt.blue_reference_pin_         -= 0.34e-9;
	}
	if(evt.elapsed_time_>1805.2 && evt.elapsed_time_<1870){
	  evt.blue_reference_anode_raw_   -= 0.935e-9;
	  evt.blue_reference_pin_         -= 0.22e-9;
	}
	if(evt.elapsed_time_>1870 && evt.elapsed_time_<2050){
	  evt.blue_reference_anode_raw_   -= 0.62e-9;
	  evt.blue_reference_pin_         -= 0.10e-9;
	}
	if(evt.elapsed_time_>2050){
	  evt.blue_reference_anode_raw_   -= 0.70e-9;
	  evt.blue_reference_pin_         -= 0.085e-9;
	}


      }
      if(rie_number_=="13042"){
	if(evt.elapsed_time_>186.25 && evt.elapsed_time_<200.25){
          evt.blue_reference_anode_raw_   -= 0.42e-9;
          evt.blue_reference_pin_         -= 0.21e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       += 0.0e-9;
        }
	if(evt.elapsed_time_>215 && evt.elapsed_time_<264){
          evt.blue_reference_anode_raw_   += 0.21e-9;
          evt.blue_reference_pin_         -= 0.0e-9;
          evt.orange_reference_anode_raw_ -= 0.14e-9;
          evt.orange_reference_pin_       -= 0.46e-9;
        }
	if(evt.elapsed_time_>264 && evt.elapsed_time_<340.25){
	  evt.blue_reference_anode_raw_   += 0.29e-9;
          evt.blue_reference_pin_         -= 0.0e-9;
          evt.orange_reference_anode_raw_ -= 0.10e-9;
          evt.orange_reference_pin_       -= 0.59e-9;
        }
	if(evt.elapsed_time_>340.25 && evt.elapsed_time_<359){
	  evt.blue_reference_anode_raw_   += 0.26e-9;
          evt.blue_reference_pin_         += 0.0e-9;
          evt.orange_reference_anode_raw_ -= 0.12e-9;
          evt.orange_reference_pin_       -= 0.6e-9;
        }
        if(evt.elapsed_time_>359 && evt.elapsed_time_<384){
	  evt.blue_reference_anode_raw_   -= 0.05e-9;
          evt.blue_reference_pin_         += 0.0e-9;
          evt.orange_reference_anode_raw_ -= 0.27e-9;
          evt.orange_reference_pin_       -= 0.55e-9;
        }
	if(evt.elapsed_time_>384 && evt.elapsed_time_<465.5){
	  evt.blue_reference_anode_raw_   += 0.23e-9;
          evt.blue_reference_pin_         += 0.01e-9;
          evt.orange_reference_anode_raw_ -= 0.12e-9;
          evt.orange_reference_pin_       -= 0.50e-9;
        }
	if(evt.elapsed_time_>465.5 && evt.elapsed_time_<530.8){
	  evt.blue_reference_anode_raw_   -= 0.11e-9;
          evt.blue_reference_pin_         -= 0.20e-9;
          evt.orange_reference_anode_raw_ -= 0.12e-9;
          evt.orange_reference_pin_       -= 0.50e-9;
        }
	if(evt.elapsed_time_>530.8 && evt.elapsed_time_<537.5){
	  evt.blue_reference_anode_raw_   += 0.22e-9;
          evt.blue_reference_pin_         += 0.01e-9;
          evt.orange_reference_anode_raw_ -= 0.11e-9;
          evt.orange_reference_pin_       -= 0.52e-9;
        }
	if(evt.elapsed_time_>537.5 && evt.elapsed_time_<557.75){
	  evt.blue_reference_anode_raw_   -= 0.12e-9;
          evt.blue_reference_pin_         -= 0.20e-9;
          evt.orange_reference_anode_raw_ -= 0.11e-9;
          evt.orange_reference_pin_       -= 0.53e-9;
        }
	if(evt.elapsed_time_>557.75 && evt.elapsed_time_<850){
	  evt.blue_reference_anode_raw_   += 0.22e-9;
          evt.blue_reference_pin_         += 0.01e-9;
          evt.orange_reference_anode_raw_ -= 0.10e-9;
          evt.orange_reference_pin_       -= 0.52e-9;
        }
	if(evt.elapsed_time_>850 && evt.elapsed_time_<1450){
	  evt.blue_reference_anode_raw_   += 0.25e-9;
          evt.blue_reference_pin_         += 0.40e-9;
          evt.orange_reference_anode_raw_ -= 0.40e-9;
          evt.orange_reference_pin_       -= 0.88e-9;
        }
	if(evt.elapsed_time_>1450){
	  evt.orange_reference_anode_raw_ -= 0.40e-9;
          evt.orange_reference_pin_       -= 0.90e-9;
	}
	if(evt.elapsed_time_>1450 && evt.elapsed_time_<1543.5){
	  evt.blue_reference_anode_raw_   -= 0.50e-9;
          evt.blue_reference_pin_         += 0.195e-9;
	}
        if(evt.elapsed_time_>1543.5 && evt.elapsed_time_<1805.2){
	  evt.blue_reference_anode_raw_   -= 0.76e-9;
          evt.blue_reference_pin_         += 0.115e-9;
	}
	if(evt.elapsed_time_>1805.2 && evt.elapsed_time_<1870){
	  evt.blue_reference_anode_raw_   -= 0.535e-9;
          evt.blue_reference_pin_         += 0.18e-9;
	}
	if(evt.elapsed_time_>1870 && evt.elapsed_time_<2050){
	  evt.blue_reference_anode_raw_   -= 0.30e-9;
	  evt.blue_reference_pin_         += 0.25e-9;
	}
	if(evt.elapsed_time_>2050){
	  evt.blue_reference_anode_raw_   -= 0.33e-9;
	  evt.blue_reference_pin_         += 0.25e-9;
	}

      }
      if(rie_number_=="13473"){
	if(evt.elapsed_time_>186.25 && evt.elapsed_time_<200.25){
          evt.blue_reference_anode_raw_   -= 0.23e-9;
          evt.blue_reference_pin_         -= 0.17e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       += 0.0e-9;
        }
	if(evt.elapsed_time_>215 && evt.elapsed_time_<264){
          evt.blue_reference_anode_raw_   += 0.11e-9;
          evt.blue_reference_pin_         += 0.015e-9;
          evt.orange_reference_anode_raw_ -= 0.10e-9;
          evt.orange_reference_pin_       -= 0.80e-9;
        }
	if(evt.elapsed_time_>264 && evt.elapsed_time_<340.25){
	  evt.blue_reference_anode_raw_   += 0.18e-9;
          evt.blue_reference_pin_         += 0.08e-9;
          evt.orange_reference_anode_raw_ -= 0.075e-9;
          evt.orange_reference_pin_       -= 0.50e-9;
        }
	if(evt.elapsed_time_>340.25 && evt.elapsed_time_<359){
	  evt.blue_reference_anode_raw_   += 0.15e-9;
          evt.blue_reference_pin_         += 0.075e-9;
          evt.orange_reference_anode_raw_ -= 0.09e-9;
          evt.orange_reference_pin_       -= 0.50e-9;
        }
        if(evt.elapsed_time_>359 && evt.elapsed_time_<384){
	  evt.blue_reference_anode_raw_   += 0.16e-9;
          evt.blue_reference_pin_         += 0.0e-9;
          evt.orange_reference_anode_raw_ -= 0.05e-9;
          evt.orange_reference_pin_       -= 1.1e-9;
        }
	if(evt.elapsed_time_>384 && evt.elapsed_time_<465.5){
	  evt.blue_reference_anode_raw_   += 0.16e-9;
          evt.blue_reference_pin_         += 0.025e-9;
          evt.orange_reference_anode_raw_ -= 0.01e-9;
          evt.orange_reference_pin_       -= 1.0e-9;
        }
	if(evt.elapsed_time_>465.5 && evt.elapsed_time_<530.8){
	  evt.blue_reference_anode_raw_   -= 0.02e-9;
          evt.blue_reference_pin_         -= 0.13e-9;
          evt.orange_reference_anode_raw_ -= 0.01e-9;
          evt.orange_reference_pin_       -= 1.0e-9;
        }
	if(evt.elapsed_time_>530.8 && evt.elapsed_time_<537.5){
	  evt.blue_reference_anode_raw_   += 0.15e-9;
          evt.blue_reference_pin_         += 0.02e-9;
          evt.orange_reference_anode_raw_ -= 0.01e-9;
          evt.orange_reference_pin_       -= 1.0e-9;
        }
	if(evt.elapsed_time_>537.5 && evt.elapsed_time_<557.75){
	  evt.blue_reference_anode_raw_   -= 0.01e-9;
          evt.blue_reference_pin_         -= 0.13e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       -= 1.0e-9;
        }
	if(evt.elapsed_time_>557.75 && evt.elapsed_time_<850){
	  evt.blue_reference_anode_raw_   += 0.16e-9;
          evt.blue_reference_pin_         += 0.025e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       -= 1.0e-9;
        }
	if(evt.elapsed_time_>850 && evt.elapsed_time_<1450){
	  evt.blue_reference_anode_raw_   += 0.12e-9;
          evt.blue_reference_pin_         += 0.22e-9;
          evt.orange_reference_anode_raw_ -= 0.05e-9;
          evt.orange_reference_pin_       -= 1.0e-9;
        }
	if(evt.elapsed_time_>1450){
	  evt.orange_reference_anode_raw_ -= 0.055e-9;
          evt.orange_reference_pin_       -= 1.0e-9;
	}
	if(evt.elapsed_time_>1450 && evt.elapsed_time_<1543.5){
	  evt.blue_reference_anode_raw_   -= 0.29e-9;
          evt.blue_reference_pin_         -= 0.02e-9;
	}
        if(evt.elapsed_time_>1543.5 && evt.elapsed_time_<1805.2){
	  evt.blue_reference_anode_raw_   -= 0.43e-9;
          evt.blue_reference_pin_         -= 0.11e-9;
	}
	if(evt.elapsed_time_>1805.2 && evt.elapsed_time_<1870){
	  evt.blue_reference_anode_raw_   -= 0.38e-9;
          evt.blue_reference_pin_         -= 0.03e-9;
	}
	if(evt.elapsed_time_>1870 && evt.elapsed_time_<2050){
	  evt.blue_reference_anode_raw_   -= 0.26e-9;
	  evt.blue_reference_pin_         += 0.05e-9;
	}
	if(evt.elapsed_time_>2050){
	  evt.blue_reference_anode_raw_   -= 0.30e-9;
	  evt.blue_reference_pin_         += 0.055e-9;
	}

      }
      if(rie_number_=="13383"){
	if(evt.elapsed_time_>186.25 && evt.elapsed_time_<200.25){
          evt.blue_reference_anode_raw_   -= 0.20e-9;
          evt.blue_reference_pin_         -= 0.13e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       += 0.0e-9;
        }
	if(evt.elapsed_time_>215 && evt.elapsed_time_<264){
          evt.blue_reference_anode_raw_   += 0.125e-9;
          evt.blue_reference_pin_         += 0.07e-9;
          evt.orange_reference_anode_raw_ += 0.006e-9;
          evt.orange_reference_pin_       -= 0.46e-9;
        }
	if(evt.elapsed_time_>264 && evt.elapsed_time_<340.25){
	  evt.blue_reference_anode_raw_   += 0.145e-9;
          evt.blue_reference_pin_         += 0.08e-9;
          evt.orange_reference_anode_raw_ += 0.05e-9;
          evt.orange_reference_pin_       -= 0.03e-9;
        }
	if(evt.elapsed_time_>340.25 && evt.elapsed_time_<359){
	  evt.blue_reference_anode_raw_   += 0.11e-9;
          evt.blue_reference_pin_         += 0.06e-9;
          evt.orange_reference_anode_raw_ += 0.02e-9;
          evt.orange_reference_pin_       -= 0.15e-9;
        }
	if(evt.elapsed_time_>359 && evt.elapsed_time_<384){
	  evt.blue_reference_anode_raw_   += 0.02e-9;
          evt.blue_reference_pin_         += 0.09e-9;
          evt.orange_reference_anode_raw_ -= 0.05e-9;
          evt.orange_reference_pin_       += 0.11e-9;
        }
	if(evt.elapsed_time_>384 && evt.elapsed_time_<465.5){
	  evt.blue_reference_anode_raw_   += 0.095e-9;
          evt.blue_reference_pin_         += 0.06e-9;
          evt.orange_reference_anode_raw_ -= 0.02e-9;
          evt.orange_reference_pin_       -= 0.20e-9;
        }
	if(evt.elapsed_time_>465.5 && evt.elapsed_time_<530.8){
	  evt.blue_reference_anode_raw_   -= 0.06e-9;
          evt.blue_reference_pin_         -= 0.06e-9;
          evt.orange_reference_anode_raw_ -= 0.02e-9;
          evt.orange_reference_pin_       -= 0.20e-9;
        }
	if(evt.elapsed_time_>530.8 && evt.elapsed_time_<537.5){
	  evt.blue_reference_anode_raw_   += 0.09e-9;
          evt.blue_reference_pin_         += 0.06e-9;
          evt.orange_reference_anode_raw_ -= 0.02e-9;
          evt.orange_reference_pin_       -= 0.19e-9;
        }
	if(evt.elapsed_time_>537.5 && evt.elapsed_time_<557.75){
	  evt.blue_reference_anode_raw_   -= 0.06e-9;
          evt.blue_reference_pin_         -= 0.06e-9;
          evt.orange_reference_anode_raw_ -= 0.02e-9;
          evt.orange_reference_pin_       -= 0.19e-9;
        }
	if(evt.elapsed_time_>557.75 && evt.elapsed_time_<850){
	  evt.blue_reference_anode_raw_   += 0.10e-9;
          evt.blue_reference_pin_         += 0.06e-9;
          evt.orange_reference_anode_raw_ -= 0.02e-9;
          evt.orange_reference_pin_       -= 0.19e-9;
        }
	if(evt.elapsed_time_>850 && evt.elapsed_time_<1450){
	  evt.blue_reference_anode_raw_   += 0.46e-9;
          evt.blue_reference_pin_         -= 0.06e-9;
          evt.orange_reference_anode_raw_ += 0.29e-9;
          evt.orange_reference_pin_       -= 0.52e-9;
        }
	if(evt.elapsed_time_>1450){
	  evt.orange_reference_anode_raw_ += 0.25e-9;
          evt.orange_reference_pin_       -= 0.60e-9;
	}
	if(evt.elapsed_time_>1450 && evt.elapsed_time_<1543.5){
	  evt.blue_reference_anode_raw_   += 0.25e-9;
          evt.blue_reference_pin_         -= 0.475e-9;
          }
        if(evt.elapsed_time_>1543.5 && evt.elapsed_time_<1805.2){
	  evt.blue_reference_anode_raw_   += 0.18e-9;
          evt.blue_reference_pin_         -= 0.635e-9;
	}
	if(evt.elapsed_time_>1805.2 && evt.elapsed_time_<1870){
	  evt.blue_reference_anode_raw_   += 0.20e-9;
          evt.blue_reference_pin_         -= 0.5e-9;
	}
	if(evt.elapsed_time_>1870 && evt.elapsed_time_<2050){
	  evt.blue_reference_anode_raw_   += 0.32e-9;
	  evt.blue_reference_pin_         -= 0.37e-9;
	}
	if(evt.elapsed_time_>2050){
	  evt.blue_reference_anode_raw_   += 0.28e-9;
	  evt.blue_reference_pin_         -= 0.365e-9;
	}
        
      }
      if(rie_number_=="13048"){
	if(evt.elapsed_time_>186.25 && evt.elapsed_time_<200.25){
          evt.blue_reference_anode_raw_   -= 0.39e-9;
          evt.blue_reference_pin_         -= 0.06e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       += 0.0e-9;
        }
	if(evt.elapsed_time_>215 && evt.elapsed_time_<264){
          evt.blue_reference_anode_raw_   += 0.17e-9;
          evt.blue_reference_pin_         += 0.015e-9;
          evt.orange_reference_anode_raw_ -= 0.16e-9;
          evt.orange_reference_pin_       -= 0.27e-9;
        }
	if(evt.elapsed_time_>264 && evt.elapsed_time_<340.25){
	  evt.blue_reference_anode_raw_   += 0.08e-9;
          evt.blue_reference_pin_         -= 0.0725e-9;
          evt.orange_reference_anode_raw_ -= 0.25e-9;
          evt.orange_reference_pin_       -= 1.05e-9;
        }
	if(evt.elapsed_time_>340.25 && evt.elapsed_time_<359){
	  evt.blue_reference_anode_raw_   += 0.05e-9;
          evt.blue_reference_pin_         -= 0.09e-9;
          evt.orange_reference_anode_raw_ -= 0.27e-9;
          evt.orange_reference_pin_       -= 1.1e-9;
        }
	if(evt.elapsed_time_>359 && evt.elapsed_time_<384){
	  evt.blue_reference_anode_raw_   -= 0.02e-9;
          evt.blue_reference_pin_         += 0.0e-9;
          evt.orange_reference_anode_raw_ -= 0.31e-9;
          evt.orange_reference_pin_       -= 0.20e-9;
        }
        if(evt.elapsed_time_>384 && evt.elapsed_time_<465.5){
	  evt.blue_reference_anode_raw_   += 0.08e-9;
          evt.blue_reference_pin_         -= 0.025e-9;
          evt.orange_reference_anode_raw_ -= 0.19e-9;
          evt.orange_reference_pin_       -= 0.25e-9;
        }
	if(evt.elapsed_time_>465.5 && evt.elapsed_time_<530.8){
	  evt.blue_reference_anode_raw_   -= 0.20e-9;
          evt.blue_reference_pin_         -= 0.11e-9;
          evt.orange_reference_anode_raw_ -= 0.19e-9;
          evt.orange_reference_pin_       -= 0.25e-9;
        }
	if(evt.elapsed_time_>530.8 && evt.elapsed_time_<537.5){
	  evt.blue_reference_anode_raw_   += 0.08e-9;
          evt.blue_reference_pin_         -= 0.03e-9;
          evt.orange_reference_anode_raw_ -= 0.16e-9;
          evt.orange_reference_pin_       -= 0.26e-9;
        }
	if(evt.elapsed_time_>537.5 && evt.elapsed_time_<557.75){
	  evt.blue_reference_anode_raw_   -= 0.19e-9;
          evt.blue_reference_pin_         -= 0.12e-9;
          evt.orange_reference_anode_raw_ -= 0.15e-9;
          evt.orange_reference_pin_       -= 0.26e-9;
        }
	if(evt.elapsed_time_>557.75 && evt.elapsed_time_<850){
	  evt.blue_reference_anode_raw_   += 0.10e-9;
          evt.blue_reference_pin_         -= 0.035e-9;
          evt.orange_reference_anode_raw_ -= 0.15e-9;
          evt.orange_reference_pin_       -= 0.26e-9;
        }
	if(evt.elapsed_time_>850 && evt.elapsed_time_<1450){
	  evt.blue_reference_anode_raw_   += 0.24e-9;
          evt.blue_reference_pin_         += 0.035e-9;
          evt.orange_reference_anode_raw_ -= 0.29e-9;
          evt.orange_reference_pin_       -= 1.25e-9;
        }
	if(evt.elapsed_time_>1450){
	  evt.orange_reference_anode_raw_ -= 0.28e-9;
          evt.orange_reference_pin_       -= 1.1e-9;
	}
	if(evt.elapsed_time_>1450 && evt.elapsed_time_<1543.5){
	  evt.blue_reference_anode_raw_   -= 0.18e-9;
          evt.blue_reference_pin_         -= 0.11e-9;
	}
        if(evt.elapsed_time_>1543.5 && evt.elapsed_time_<1805.2){
	  evt.blue_reference_anode_raw_   -= 0.32e-9;
          evt.blue_reference_pin_         -= 0.165e-9;
	}
	if(evt.elapsed_time_>1805.2 && evt.elapsed_time_<1870){
	  evt.blue_reference_anode_raw_   -= 0.20e-9;
          evt.blue_reference_pin_         -= 0.115e-9;
	}
	if(evt.elapsed_time_>1870 && evt.elapsed_time_<2050){
	  evt.blue_reference_anode_raw_   -= 0.07e-9;
	  evt.blue_reference_pin_         -= 0.065e-9;
	}
	if(evt.elapsed_time_>2050){
	  evt.blue_reference_anode_raw_   -= 0.12e-9;
	  evt.blue_reference_pin_         -= 0.065e-9;
	}

      }

    } // end if UVa, Run4
    
      
    //
    // Corrections for Run5
    //
    if(run_num_ == run_num::run5){
      
      if(rie_number_=="6714"){
        if(evt.elapsed_time_>650 && evt.elapsed_time_<820){
          evt.blue_reference_anode_raw_   += 0.0e-9;
          evt.blue_reference_pin_         -= 0.01e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       -= 0.01e-9;
        } 
      }
      if(rie_number_=="6415"){
        if(evt.elapsed_time_>650 && evt.elapsed_time_<820){
          evt.blue_reference_anode_raw_   += 0.0e-9;
          evt.blue_reference_pin_         -= 0.005e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       -= 0.015e-9;
        } 
      }
      if(rie_number_=="7603"){
        if(evt.elapsed_time_>650 && evt.elapsed_time_<820){
          evt.blue_reference_anode_raw_   -= 0.0e-9;
          evt.blue_reference_pin_         -= 0.015e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       -= 0.02e-9;
        } 
      }
      if(rie_number_=="7205"){
        if(evt.elapsed_time_>650 && evt.elapsed_time_<820){
          evt.blue_reference_anode_raw_   += 0.0e-9;
          evt.blue_reference_pin_         -= 0.01e-9;
          evt.orange_reference_anode_raw_ += 0.0e-9;
          evt.orange_reference_pin_       -= 0.015e-9;
        } 
      }
      if(rie_number_=="8127"){
        if(evt.elapsed_time_>650 && evt.elapsed_time_<820){
          evt.blue_reference_anode_raw_   += 0.0e-9;
          evt.blue_reference_pin_         -= 0.01e-9;
          evt.orange_reference_anode_raw_ -= 0.0e-9;
          evt.orange_reference_pin_       -= 0.015e-9;
        } 
      }

    } // end if UVa, Run5


    

  }  // end if Site is UVa


  return;
}



//=============================================================================
// 
// Utility Class for Plotting
//
//=============================================================================

class plotInfo{
    
 public: 

  TString whichVpt;                  // which vpt to plot
 
  TString yBranch, xBranch;          // branches varexp for x,y variables to plot 
  TString yBranch_err, xBranch_err;  // branches varex for x,y, errors to plot

  TString title;                     // plot title
  TString xAxisTitle, yAxisTitle;    // titles
  
  TString extraCuts;                 // extra cuts to add  
  
  bool applyAveraging;               // boolean to apply averaging
  double numToAvg;                   // number of points to use in rolling average

  bool applyNormalize;               // boolean to normalize data to first data point
 
  bool    applyFit;                  // bool to apply fit or not
  TString formula;                   // TString of fit formula
  TString formulaName;               // Human readable description of formula
  double  rangeLow;                  // low point of fit range
  double  rangeHigh;                 // high point of fit range
  vector<int>     constraints_param; // parameter constraints, this Param
  vector<double>  constraints_high;  // parameter constraints, high 
  vector<double>  constraints_low;   // parameter constraints, low

  vector<int>     initialVals_param; // initial values, this Param
  vector<double>  initialVals_val;   // initial values, initial value

  vector<int>     paramNames_param;  // parameter names, this Param
  vector<TString> paramNames_name;   // parameter names, name

  
  // Constructor
  plotInfo():
    whichVpt(""), 
    yBranch(""), xBranch(""), yBranch_err(""), xBranch_err(""),
    title(""), xAxisTitle(""), yAxisTitle(""),
    extraCuts(""),
    applyAveraging(false), numToAvg(1),
    applyNormalize(false), 
    applyFit(false), formula(""), formulaName(""), 
    rangeLow(0), rangeHigh(100000) {}

  // Alternative Contsructor
  plotInfo(TString plotTitle):
    whichVpt(""), 
    yBranch(""), xBranch(""), yBranch_err(""), xBranch_err(""),
    title(plotTitle), xAxisTitle(""), yAxisTitle(""),
    extraCuts(""),
    applyAveraging(false), numToAvg(1),
    applyNormalize(false), 
    applyFit(false), formula(""), formulaName(""), 
    rangeLow(0), rangeHigh(100000) {}
    

  void set_Averaging(double num=5)   { applyAveraging=true; numToAvg=num; }
  void set_Normalize()               { applyNormalize=true;               }

  void set_Fit(TString eqnName, TString equation, double begin=0.0, double end=10000.0){
    applyFit    = true;
    formulaName = eqnName;
    formula     = equation;
    rangeLow    = begin;
    rangeHigh   = end;
  }
  void set_Param_Constraint(int thisPar, double lowVal, double highVal){
    constraints_param.push_back(thisPar);
    constraints_low.push_back(lowVal);
    constraints_high.push_back(highVal);
  }
  void set_Intial_Values(int thisPar, double val){
    initialVals_param.push_back(thisPar);
    initialVals_val.push_back(val);
  }
  void set_Param_Name(int thisPar, TString name){ 
    paramNames_param.push_back(thisPar);
    paramNames_name.push_back(name);
  }

  void reset(){
    whichVpt=""; 
    yBranch=""; xBranch=""; yBranch_err=""; xBranch_err="";
    title=""; xAxisTitle=""; yAxisTitle="";
    extraCuts="";
    applyAveraging=false; numToAvg=1;
    applyNormalize=false; 
    applyFit=false; formula=""; formulaName=""; 
    rangeLow=0; rangeHigh=100000;
    constraints_param.clear();
    constraints_low.clear();
    constraints_high.clear();
    initialVals_param.clear();
    initialVals_val.clear();
    paramNames_param.clear();
    paramNames_name.clear();
  }

};


//=============================================================================
// 
// Utility Class for Analyzer
//
//=============================================================================

class vpt_analysis{

 public:

  analysis_type::analysis_type analysis_type_;

  TFile *data_file_;
  TFile *plot_file_;
  TFile *fit_file_;

  TString data_file_name_;
  TString plot_file_name_;
  TString fit_file_name_;

  std::vector<double>  v_blue_ref_fit_c_;
  std::vector<double>  v_blue_ref_fit_a1_;
  std::vector<double>  v_blue_ref_fit_t1_;
  std::vector<double>  v_blue_ref_fit_a2_;
  std::vector<double>  v_blue_ref_fit_t2_;
  std::vector<double>  v_blue_ref_fit_all_t_;
  std::vector<double>  v_blue_ref_fit_chi2_;
  std::vector<double>  v_blue_ref_fit_drop_;
  std::vector<TString> v_blue_ref_fit_rieNum_;

  std::vector<double>  v_orng_ref_fit_c_;
  std::vector<double>  v_orng_ref_fit_a1_;
  std::vector<double>  v_orng_ref_fit_t1_;
  std::vector<double>  v_orng_ref_fit_a2_;
  std::vector<double>  v_orng_ref_fit_t2_;
  std::vector<double>  v_orng_ref_fit_all_t_;
  std::vector<double>  v_orng_ref_fit_chi2_;
  std::vector<double>  v_orng_ref_fit_drop_;
  std::vector<TString> v_orng_ref_fit_rieNum_;


  std::vector< vptInfo* > vpt_list_;
  
  vpt_analysis(analysis_type::analysis_type this_analysis);
  virtual ~vpt_analysis();
  
  void get_raw_data();
  void make_friends();
  void get_extrapolated_dark_current();
  void get_pin_corrections();
  void get_cathode_corrections();
  void get_anode_corrections();
  void get_integrated_charge();
  void get_filter_results();
  void get_plots(vector<plotInfo> &plotList);
  void get_overlay_plots(v_vpt_plot &plotList, plotInfo plot, TString groupDescription="");
  void get_fit_result_plots();

};

//_____________________________________________________________________________
//
// Constructor for Analysis Class
//
vpt_analysis::vpt_analysis(analysis_type::analysis_type this_analysis){


  analysis_type_ = this_analysis;

  data_file_ = NULL;
  plot_file_ = NULL;
  fit_file_  = NULL;

  data_file_name_ = "../data/vpt_conditioning_data.root";
  plot_file_name_ = "../plots/vpt_conditioning_plots.root";
  fit_file_name_  = "../plots/vpt_conditioning_fits.root";

  // Open ROOT files
  if(analysis_type_ == analysis_type::analyze){
    
    data_file_ = new TFile( data_file_name_, "recreate" );
  
  }
  if(analysis_type_ == analysis_type::plot){

    data_file_ = new TFile( data_file_name_, "read" );
    plot_file_ = new TFile( plot_file_name_, "recreate" );
    
    // Check if root file has been made
    bool is_zombie = data_file_->IsZombie();
    
    if(is_zombie){
      cout << "No ROOT file exists for vpt analysis..." << endl;
      cout << "  Please run: root -l -b -q vpt_analyzer.C++ first..." << endl;
    }

  }
  if(analysis_type_ == analysis_type::fit){

    data_file_ = new TFile( data_file_name_, "read" );
    fit_file_  = new TFile( fit_file_name_,  "recreate" );
    
    // Check if root file has been made
    bool is_zombie = data_file_->IsZombie();
    
    if(is_zombie){
      cout << "No ROOT file exists for vpt analysis..." << endl;
      cout << "  Please run: root -l -b -q vpt_analyzer.C++ first..." << endl;
    }

  }
  

  //
  // Parameters to help intialize vptInfo objects
  //
  double run_begin = 0.0;
  vector<TString> friend_trees;
 
  
  //
  // Brunel, Run 2
  //
  run_begin = 0.0;
  friend_trees.push_back("brunel_run2_vpt947");
  
  vptInfo *vpt947_ = new vptInfo(site::brunel, run_num::run2, "947", run_begin, friend_trees, kAzure+2);
  vpt_list_.push_back(vpt947_);

  friend_trees.clear();
  
  
  //
  // UVa, Run 1
  //
  run_begin = 0.0;
  //friend_trees.push_back("uva_run1_vpt2182");
  //friend_trees.push_back("uva_run1_vpt2183");
  //friend_trees.push_back("uva_run1_vpt2184");
  //friend_trees.push_back("uva_run1_vpt2185");

  //vptInfo *vpt2181_ = new vptInfo(site::uva, run_num::run1, "2181", run_begin, friend_trees, kOrange+7); // Excluded Due to Noise
  //vpt_list_.push_back(vpt2181_);

  vptInfo *vpt2182_ = new vptInfo(site::uva, run_num::run1, "2182", run_begin, friend_trees, kRed+2);
  vpt_list_.push_back(vpt2182_);

  vptInfo *vpt2183_ = new vptInfo(site::uva, run_num::run1, "2183", run_begin, friend_trees, kGreen+1);
  vpt_list_.push_back(vpt2183_);

  vptInfo *vpt2184_ = new vptInfo(site::uva, run_num::run1, "2184", run_begin, friend_trees, kBlue);
  vpt_list_.push_back(vpt2184_);

  vptInfo *vpt2185_ = new vptInfo(site::uva, run_num::run1, "2185", run_begin, friend_trees, kMagenta+2);
  vpt_list_.push_back(vpt2185_);

  friend_trees.clear();


  
  //
  // UVa, Run 2
  //
  run_begin = 474.0;
  friend_trees.push_back("uva_run2_vpt7095");
  friend_trees.push_back("uva_run2_vpt7112");
  friend_trees.push_back("uva_run2_vpt7120");
  
  vptInfo *vpt7095_ = new vptInfo(site::uva, run_num::run2, "7095", run_begin, friend_trees, kOrange+7);
  vpt_list_.push_back(vpt7095_);

  //vptInfo *vpt7182_ = new vptInfo(site::uva, run_num::run2, "7182", run_begin, friend_trees, kRed+2); // Excluded Due to Noise
  //vpt_list_.push_back(vpt7182_);

  vptInfo *vpt7112_ = new vptInfo(site::uva, run_num::run2, "7112", run_begin, friend_trees, kGreen+1);
  vpt_list_.push_back(vpt7112_);
  
  vptInfo *vpt7120_ = new vptInfo(site::uva, run_num::run2, "7120", run_begin, friend_trees, kBlue);
  vpt_list_.push_back(vpt7120_); 

  vptInfo *vpt7099_ = new vptInfo(site::uva, run_num::run2, "7099", run_begin, friend_trees, kMagenta+2);
  vpt_list_.push_back(vpt7099_);

  friend_trees.clear();

  
  //
  // UVa, Run 3
  //
  run_begin = 380.0;
  friend_trees.push_back("uva_run3_vpt12920");
  friend_trees.push_back("uva_run3_vpt13041");
  friend_trees.push_back("uva_run3_vpt12797");
  
  vptInfo *vpt12199_ = new vptInfo(site::uva, run_num::run3, "12199", run_begin, friend_trees, kOrange+7);
  vpt_list_.push_back(vpt12199_);

  vptInfo *vpt12920_ = new vptInfo(site::uva, run_num::run3, "12920", run_begin, friend_trees, kRed+2);
  vpt_list_.push_back(vpt12920_);

  vptInfo *vpt13041_ = new vptInfo(site::uva, run_num::run3, "13041", run_begin, friend_trees, kGreen+1);
  vpt_list_.push_back(vpt13041_);
 
  vptInfo *vpt12797_ = new vptInfo(site::uva, run_num::run3, "12797", run_begin, friend_trees, kBlue);
  vpt_list_.push_back(vpt12797_);
  
  vptInfo *vpt13047_ = new vptInfo(site::uva, run_num::run3, "13047", run_begin, friend_trees, kMagenta+2);
  vpt_list_.push_back(vpt13047_);
  
  friend_trees.clear();
  

  //
  // UVa, Run 4
  //
  run_begin = 385.0;
  friend_trees.push_back("uva_run4_vpt13042");
  friend_trees.push_back("uva_run4_vpt13473");
  friend_trees.push_back("uva_run4_vpt13383");
 
  vptInfo *vpt14649_ = new vptInfo(site::uva, run_num::run4, "14649", run_begin, friend_trees, kOrange+7);
  vpt_list_.push_back(vpt14649_);

  vptInfo *vpt13042_ = new vptInfo(site::uva, run_num::run4, "13042", run_begin, friend_trees, kRed+2);
  vpt_list_.push_back(vpt13042_);

  vptInfo *vpt13473_ = new vptInfo(site::uva, run_num::run4, "13473", run_begin, friend_trees, kGreen+1);
  vpt_list_.push_back(vpt13473_);

  vptInfo *vpt13383_ = new vptInfo(site::uva, run_num::run4, "13383", run_begin, friend_trees, kBlue);
  vpt_list_.push_back(vpt13383_);

  vptInfo *vpt13048_ = new vptInfo(site::uva, run_num::run4, "13048", run_begin, friend_trees, kMagenta+2);
  vpt_list_.push_back(vpt13048_);
  
  friend_trees.clear();

  
  //
  // UVa, Run 5
  //
  run_begin = 650.0;
  friend_trees.push_back("uva_run5_vpt6714");
  friend_trees.push_back("uva_run5_vpt7603");
  friend_trees.push_back("uva_run5_vpt7205");
  
  vptInfo *vpt6714_ = new vptInfo(site::uva, run_num::run5, "6714", run_begin, friend_trees, kOrange+7);
  vpt_list_.push_back(vpt6714_);
  
  vptInfo *vpt6415_ = new vptInfo(site::uva, run_num::run5, "6415", run_begin, friend_trees, kRed+2);
  vpt_list_.push_back(vpt6415_);
  
  vptInfo *vpt7603_ = new vptInfo(site::uva, run_num::run5, "7603", run_begin, friend_trees, kGreen+1);
  vpt_list_.push_back(vpt7603_);
  
  vptInfo *vpt7205_ = new vptInfo(site::uva, run_num::run5, "7205", run_begin, friend_trees, kBlue);
  vpt_list_.push_back(vpt7205_);

  vptInfo *vpt8127_ = new vptInfo(site::uva, run_num::run5, "8127", run_begin, friend_trees, kMagenta+2);
  vpt_list_.push_back(vpt8127_);
  
  friend_trees.clear();

  
  //
  // UVa, Run 6
  //
  run_begin = 446.0;
  friend_trees.push_back("uva_run6_vpt5620");
  //friend_trees.push_back("uva_run6_vpt8172");
  friend_trees.push_back("uva_run6_vpt8605");
  friend_trees.push_back("uva_run6_vpt14765");
  //friend_trees.push_back("uva_run6_vpt14753");

  vptInfo *vpt5620_ = new vptInfo(site::uva, run_num::run6, "5620", run_begin, friend_trees, kOrange+7);
  vpt_list_.push_back(vpt5620_);

  vptInfo *vpt8172_ = new vptInfo(site::uva, run_num::run6, "8172", run_begin, friend_trees, kRed+2);
  vpt_list_.push_back(vpt8172_);

  vptInfo *vpt8605_ = new vptInfo(site::uva, run_num::run6, "8605", run_begin, friend_trees, kGreen+1);
  vpt_list_.push_back(vpt8605_);

  vptInfo *vpt14765_ = new vptInfo(site::uva, run_num::run6, "14765", run_begin, friend_trees, kBlue);
  vpt_list_.push_back(vpt14765_);

  vptInfo *vpt14753_ = new vptInfo(site::uva, run_num::run6, "14753", run_begin, friend_trees, kMagenta+2);
  vpt_list_.push_back(vpt14753_);

  friend_trees.clear();
  

} // end vpt_analysis constructor


//_____________________________________________________________________________
//
// vpt_analysis Destructor
//
vpt_analysis::~vpt_analysis(){

  cout << endl;

  if(data_file_) data_file_->Close();
    
  if(plot_file_) plot_file_->Close();
 
  if(fit_file_){
    fit_file_->Write();
    fit_file_->Close();
  }

  vpt_list_.clear();

}


//_____________________________________________________________________________
//
// Get raw data from root file
//
void vpt_analysis::get_raw_data(){
  
  bool verbose = false;

  // Loop over raw data files and fill root file
  for(std::vector<vptInfo*>::const_iterator tIter = vpt_list_.begin(); tIter != vpt_list_.end(); ++tIter){
    
    vptInfo *vpt = *tIter; // ptr to iterator
    
    // Print Status
    cout << "  Reading Raw Data File: " << vpt->raw_data_file_ << endl;
   
    // Declare and open root file
    TTree *tree = new TTree(vpt->tree_name_, vpt->tree_name_);  
    tree->SetDirectory(data_file_);

    // Declare Utility Vars
    double timeLast=0, deltaTime=0, deltaTimeLast=0;

    //
    //Create Branches for Each Variable on input tree
    //
    measurement evt;
    initialize(evt);

    // Brunel Site
    if(vpt->site_==site::brunel){

      // Raw Data Variables For Brunel, Run1
      if(vpt->run_num_==run_num::run1){

	tree->Branch("date",                                      &evt.date_,                                     "date/F");
	tree->Branch("time",                                      &evt.time_,                                     "time/F");
	tree->Branch("elapsed_time",                              &evt.elapsed_time_,                             "elapsed_time/F"); 
	tree->Branch("blue_reference_anode_raw",                  &evt.blue_reference_anode_raw_,                 "blue_reference_anode_raw/F");
        tree->Branch("blue_reference_anode_raw_std_dev",          &evt.blue_reference_anode_raw_std_dev_,         "blue_reference_anode_raw_std_dev/F");
        tree->Branch("blue_reference_anode_raw_err",              &evt.blue_reference_anode_raw_err_,             "blue_reference_anode_raw_err/F");
        tree->Branch("blue_reference_pin",                        &evt.blue_reference_pin_,                       "blue_reference_pin/F");
        tree->Branch("blue_reference_pin_std_dev",                &evt.blue_reference_pin_std_dev_,               "blue_reference_pin_std_dev/F");
        tree->Branch("blue_reference_pin_err",                    &evt.blue_reference_pin_err_,                   "blue_reference_pin_err/F");
	tree->Branch("blue_reference_vpt_div_pin",                &evt.blue_reference_vpt_div_pin_,               "blue_reference_vpt_div_pin/F");
	tree->Branch("blue_reference_vpt_div_pin_NIM_corrected",  &evt.blue_reference_vpt_div_pin_NIM_corrected_, "blue_reference_vpt_div_pin_NIM_corrected/F");
	tree->Branch("integrated_charge",                         &evt.integrated_charge_,                        "integrated_charge/F"); 
	tree->Branch("integrated_charge_err",                     &evt.integrated_charge_err_,                    "integrated_charge_err/F"); 
	tree->Branch("temperature_vpt",                           &evt.temperature_vpt_,                          "temperature_vpt/F");
	tree->Branch("temperature_pa",                            &evt.temperature_pa_,                           "temperature_pa/F");
	tree->Branch("temperature_sa",                            &evt.temperature_sa_,                           "temperature_sa/F");
	
	// Simple Relative Error Filter
	tree->Branch(    "relative_err_filter",                   &evt.relative_err_filter_,                       "relative_err_filter/F");  
      }

      // Raw Data Variables For Brunel, Run1
      if(vpt->run_num_==run_num::run2){

	tree->Branch("date",                                      &evt.date_,                                     "date/F");
	tree->Branch("time",                                      &evt.time_,                                     "time/F");
	tree->Branch("elapsed_time",                              &evt.elapsed_time_,                             "elapsed_time/F"); 
	tree->Branch("blue_reference_anode_raw",                  &evt.blue_reference_anode_raw_,                 "blue_reference_anode_raw/F");
        tree->Branch("blue_reference_anode_raw_std_dev",          &evt.blue_reference_anode_raw_std_dev_,         "blue_reference_anode_raw_std_dev/F");
        tree->Branch("blue_reference_anode_raw_err",              &evt.blue_reference_anode_raw_err_,             "blue_reference_anode_raw_err/F");
        tree->Branch("blue_reference_pin",                        &evt.blue_reference_pin_,                       "blue_reference_pin/F");
        tree->Branch("blue_reference_pin_std_dev",                &evt.blue_reference_pin_std_dev_,               "blue_reference_pin_std_dev/F");
        tree->Branch("blue_reference_pin_err",                    &evt.blue_reference_pin_err_,                   "blue_reference_pin_err/F");
	tree->Branch("blue_reference_vpt_div_pin",                &evt.blue_reference_vpt_div_pin_,               "blue_reference_vpt_div_pin/F");
	tree->Branch("blue_reference_vpt_div_pin_NIM_corrected",  &evt.blue_reference_vpt_div_pin_NIM_corrected_, "blue_reference_vpt_div_pin_NIM_corrected/F");
	tree->Branch("integrated_charge",                         &evt.integrated_charge_,                        "integrated_charge/F"); 
	tree->Branch("integrated_charge_err",                     &evt.integrated_charge_err_,                    "integrated_charge_err/F"); 
	tree->Branch("incremental_charge",                        &evt.incremental_charge_,                       "incremental_charge/F"); 
	tree->Branch("temperature_vpt",                           &evt.temperature_vpt_,                          "temperature_vpt/F");
	tree->Branch("temperature_pa",                            &evt.temperature_pa_,                           "temperature_pa/F");
	tree->Branch("temperature_sa",                            &evt.temperature_sa_,                           "temperature_sa/F");
	tree->Branch("temperature_led",                           &evt.temperature_led_,                          "temperature_led/F");
	tree->Branch("temperature_lab",                           &evt.temperature_lab_,                          "temperature_lab/F");
	
	// Simple Relative Error Filter
	tree->Branch(    "relative_err_filter",                   &evt.relative_err_filter_,                       "relative_err_filter/F");  
      }

      
    } // end if brunel site

    
    // UVa site
    if(vpt->site_==site::uva){


      // Rig Measurements
      tree->Branch(    "elapsed_time",                             &evt.elapsed_time_,                             "elapsed_time/F"); 
      tree->Branch(    "angle",                                    &evt.angle_,                                    "angle/F");


      // blue reference led measurements
      tree->Branch(    "blue_reference_anode_raw",                 &evt.blue_reference_anode_raw_,                 "blue_reference_anode_raw/F");
      tree->Branch(    "blue_reference_anode_raw_std_dev",         &evt.blue_reference_anode_raw_std_dev_,         "blue_reference_anode_raw_std_dev/F");
      tree->Branch(    "blue_reference_anode_raw_err",             &evt.blue_reference_anode_raw_err_,             "blue_reference_anode_raw_err/F");

      if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) &&  !(vpt->run_num_==run_num::run3) ){
	tree->Branch(  "blue_reference_cathode_current",           &evt.blue_reference_cathode_current_,           "blue_reference_cathode_current/F");
	tree->Branch(  "blue_reference_cathode_current_std_dev",   &evt.blue_reference_cathode_current_std_dev_,   "blue_reference_cathode_current_std_dev/F");
	tree->Branch(  "blue_reference_cathode_current_err",       &evt.blue_reference_cathode_current_err_,       "blue_reference_cathode_current_err/F");
      }      

      tree->Branch(    "blue_reference_led_frequency",             &evt.blue_reference_led_frequency_,             "blue_reference_led_frequency/F");
      tree->Branch(    "blue_reference_pin",                       &evt.blue_reference_pin_,                       "blue_reference_pin/F");
      tree->Branch(    "blue_reference_pin_std_dev",               &evt.blue_reference_pin_std_dev_,               "blue_reference_pin_std_dev/F");
      tree->Branch(    "blue_reference_pin_err",                   &evt.blue_reference_pin_err_,                   "blue_reference_pin_err/F");


      // blue load led measurements
      tree->Branch(    "blue_load_anode_raw",                      &evt.blue_load_anode_raw_,                      "blue_load_anode_raw/F");
      tree->Branch(    "blue_load_anode_raw_std_dev",              &evt.blue_load_anode_raw_std_dev_,              "blue_load_anode_raw_std_dev/F");
      tree->Branch(    "blue_load_anode_raw_err",                  &evt.blue_load_anode_raw_err_,                  "blue_load_anode_raw_err/F");      

      if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) ){
	tree->Branch(  "blue_load_dark_cathode_current",           &evt.blue_load_dark_cathode_current_,           "blue_load_dark_cathode_current/F");
	tree->Branch(  "blue_load_dark_cathode_current_std_dev",   &evt.blue_load_dark_cathode_current_std_dev_,   "blue_load_dark_cathode_current_std_dev/F");
	tree->Branch(  "blue_load_dark_cathode_current_err",       &evt.blue_load_dark_cathode_current_err_,       "blue_load_dark_cathode_current_err/F");
      }

      tree->Branch(    "blue_load_cathode_current_raw",            &evt.blue_load_cathode_current_raw_,            "blue_load_cathode_current_raw/F");
      tree->Branch(    "blue_load_cathode_current_raw_std_dev",    &evt.blue_load_cathode_current_raw_std_dev_,    "blue_load_cathode_current_raw_std_dev/F");
      tree->Branch(    "blue_load_cathode_current_raw_err",        &evt.blue_load_cathode_current_raw_err_,        "blue_load_cathode_current_raw_err/F");
      tree->Branch(    "blue_load_led_frequency",                  &evt.blue_load_led_frequency_,                  "blue_load_led_frequency/F");
      tree->Branch(    "blue_load_led_isOn",                       &evt.blue_load_led_isOn_,                       "blue_load_led_isOn/F");
      tree->Branch(    "blue_load_pin",                            &evt.blue_load_pin_,                            "blue_load_pin/F");
      tree->Branch(    "blue_load_pin_std_dev",                    &evt.blue_load_pin_std_dev_,                    "blue_load_pin_std_dev/F");
      tree->Branch(    "blue_load_pin_err",                        &evt.blue_load_pin_err_,                        "blue_load_pin_err/F");


      // orange reference led measurements
      if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2)  ){
	tree->Branch(  "orange_reference_anode_raw",               &evt.orange_reference_anode_raw_,               "orange_reference_anode_raw/F");
	tree->Branch(  "orange_reference_anode_raw_std_dev",       &evt.orange_reference_anode_raw_std_dev_,       "orange_reference_anode_raw_std_dev/F");
	tree->Branch(  "orange_reference_anode_raw_err",           &evt.orange_reference_anode_raw_err_,           "orange_reference_anode_raw_err/F");

	if( !(vpt->run_num_==run_num::run3) ){
	  tree->Branch("orange_reference_cathode_current",         &evt.orange_reference_cathode_current_,         "orange_reference_cathode_current/F");
	  tree->Branch("orange_reference_cathode_current_std_dev", &evt.orange_reference_cathode_current_std_dev_, "orange_reference_cathode_current_std_dev/F");
	  tree->Branch("orange_reference_cathode_current_err",     &evt.orange_reference_cathode_current_err_,     "orange_reference_cathode_current_err/F");
	}

	tree->Branch(  "orange_reference_led_frequency",           &evt.orange_reference_led_frequency_,           "orange_reference_led_frequency/F");
	tree->Branch(  "orange_reference_pin",                     &evt.orange_reference_pin_,                     "orange_reference_pin/F");
	tree->Branch(  "orange_reference_pin_std_dev",             &evt.orange_reference_pin_std_dev_,             "orange_reference_pin_std_dev/F");
	tree->Branch(  "orange_reference_pin_err",                 &evt.orange_reference_pin_err_,                 "orange_reference_pin_err/F");
      } // end if orange led mearsurements


      // Amplifier Pulsing
      if( !(vpt->run_num_==run_num::run5) && !(vpt->run_num_==run_num::run6) ){
	tree->Branch(  "amp_pin_in",                               &evt.amp_pin_in_,                               "amp_pin_in/F");
	tree->Branch(  "amp_pin_in_std_dev",                       &evt.amp_pin_in_std_dev_,                       "amp_pin_in_std_dev/F");
	tree->Branch(  "amp_pin_in_err",                           &evt.amp_pin_in_err_,                           "amp_pin_in_err/F");
	tree->Branch(  "amp_pin_out",                              &evt.amp_pin_out_,                              "amp_pin_out/F");
	tree->Branch(  "amp_pin_out_std_dev",                      &evt.amp_pin_out_std_dev_,                      "amp_pin_out_std_dev/F");
	tree->Branch(  "amp_pin_out_err",                          &evt.amp_pin_out_err_,                          "amp_pin_out_std_dev/F");
	tree->Branch(  "amp_vpt_in",                               &evt.amp_vpt_in_,                               "amp_vpt_in/F");
	tree->Branch(  "amp_vpt_in_std_dev",                       &evt.amp_vpt_in_std_dev_,                       "amp_vpt_in_std_dev/F");
	tree->Branch(  "amp_vpt_in_err",                           &evt.amp_vpt_in_err_,                           "amp_vpt_in_err/F");
	tree->Branch(  "amp_vpt_out",                              &evt.amp_vpt_out_,                              "amp_vpt_out/F");
	tree->Branch(  "amp_vpt_out_std_dev",                      &evt.amp_vpt_out_std_dev_,                      "amp_vpt_out_std_dev/F");
	tree->Branch(  "amp_vpt_out_err",                          &evt.amp_vpt_out_err_,                          "amp_vpt_out_err/F");
      }


      // Environmental Variables
      tree->Branch(    "temperature",                              &evt.temperature_,                              "temperature/F");
      tree->Branch(    "temperature_std_dev",                      &evt.temperature_std_dev_,                      "temperature_std_dev/F");
      tree->Branch(    "temperature_err",                          &evt.temperature_err_,                          "temperature_err/F");
      tree->Branch(    "humidity",                                 &evt.humidity_,                                 "humidity/F");
      tree->Branch(    "humidity_std_dev",                         &evt.humidity_std_dev_,                         "humidity_std_dev/F");
      tree->Branch(    "humidity_err",                             &evt.humidity_err_,                             "humidity_err/F");  

      // Simple Relative Error Filter
      tree->Branch(    "relative_err_filter",                      &evt.relative_err_filter_,                       "relative_err_filter/F");  
    }

   
    //
    // Open the raw data file 
    //
    ifstream raw_file(vpt->raw_data_file_, ios::in);  
    if( !raw_file.is_open() ){
      cout << "Error Opening File: " << vpt->raw_data_file_ << endl;
    }


    //
    // Brunel has seperate data files for temperature and vpt measurements
    //
    ifstream raw_file_2;
    TString  raw_data_file_2_name = "";
    if(vpt->site_==site::brunel){

      raw_data_file_2_name = vpt->raw_data_file_;
      raw_data_file_2_name.ReplaceAll(".dat", "_temp.dat");

      raw_file_2.open(raw_data_file_2_name.Data(), ios::in);
      if( !raw_file_2.is_open() ){
	cout << "Error Opening File: " << raw_data_file_2_name << endl;
      }

    }

   
    //
    // Fill tree with raw data values, order matters here
    //
    int    entry_count = -1;
    double time_offset = 0.0;
    double time_zero_temp = 0;
    double rel_err_thresh = 1.0;
    while(raw_file.good() && !raw_file.eof()){

      entry_count++; // simple counter
  
      //
      // Initialize Vars
      //
      initialize(evt);

      //
      // Read in Raw Files For Brunel
      //
      if(vpt->site_ == site::brunel){
	
	if(vpt->run_num_ == run_num::run1 || vpt->run_num_ == run_num::run2){

	  raw_file >> evt.date_;
	  raw_file >> evt.time_;
	  raw_file >> evt.elapsed_time_;

	  if(vpt->run_num_ == run_num::run2){
	    if(entry_count==0) time_offset = evt.elapsed_time_;
	    evt.elapsed_time_ -= time_offset;
	  }

	  raw_file >> evt.blue_reference_anode_raw_;
	  raw_file >> evt.blue_reference_anode_raw_std_dev_;
	  evt.blue_reference_anode_raw_std_dev_ /= 2.354;
	  evt.blue_reference_anode_raw_err_      = evt.blue_reference_anode_raw_std_dev_/sqrt(1000);

	  if(evt.blue_reference_anode_raw_err_/evt.blue_reference_anode_raw_ > rel_err_thresh) evt.relative_err_filter_ = 0;

	  raw_file >> evt.blue_reference_pin_;
	  raw_file >> evt.blue_reference_pin_std_dev_;
	  evt.blue_reference_pin_std_dev_ /= 2.354;
	  evt.blue_reference_pin_err_      = evt.blue_reference_pin_std_dev_/sqrt(1000);

	  if(evt.blue_reference_pin_err_/evt.blue_reference_pin_ > rel_err_thresh) evt.relative_err_filter_ = 0;

	  raw_file >> evt.blue_reference_vpt_div_pin_;
	  raw_file >> evt.blue_reference_vpt_div_pin_NIM_corrected_;
	  raw_file >> evt.integrated_charge_;
	  evt.integrated_charge_err_ = evt.integrated_charge_*0.001;  // 0.1% error for now
 
	  if(vpt->run_num_==run_num::run2){
	    raw_file >> evt.incremental_charge_;
	  }

	  if(entry_count==0){
	    raw_file_2 >> evt.date_temp_;
	    raw_file_2 >> evt.time_temp_;
	    raw_file_2 >> evt.elapsed_time_temp_;

	    time_zero_temp = evt.elapsed_time_temp_;
	  }

	  if( (evt.elapsed_time_>=time_zero_temp) && !(raw_file_2.eof()) ){
	    
	    if(evt.elapsed_time_>time_zero_temp && entry_count!=0){
	      raw_file_2 >> evt.date_temp_;
	      raw_file_2 >> evt.time_temp_;
	      raw_file_2 >> evt.elapsed_time_temp_;
	    }

	    raw_file_2 >> evt.temperature_vpt_;
	    raw_file_2 >> evt.temperature_pa_;

	    if(vpt->run_num_==run_num::run2){
	      raw_file_2 >> evt.temperature_led_;
	      raw_file_2 >> evt.temperature_lab_;
	    }

	    raw_file_2 >> evt.temperature_sa_;
	    
	  }	    


	  if(verbose && (entry_count%1000==0 || entry_count<2 || raw_file.eof() ) ){
	    cout << endl;
	    cout << "=====================================================================================" << endl ;
	    cout << "    Printing Variables Read In, -99.9=variable not filled, -1=NaN from data file..." << endl;
	    cout << "      entry_count                    = " << entry_count << endl;
	    cout << "      date                           = " << evt.date_ << endl;
	    cout << "      time                           = " << evt.time_ << endl;
	    cout << "      elapsed time                   = " << evt.elapsed_time_ << endl;
	    cout << "      blue ref anode                 = " << evt.blue_reference_anode_raw_ << endl;
	    cout << "      blue ref anode std dev         = " << evt.blue_reference_anode_raw_std_dev_ << endl;
	    cout << "      blue ref pin                   = " << evt.blue_reference_pin_ << endl;
	    cout << "      blue ref pin std dev           = " << evt.blue_reference_pin_std_dev_ << endl;
	    cout << "      blue ref vpt/pin               = " << evt.blue_reference_vpt_div_pin_ << endl;
	    cout << "      blue ref vpt/pin NIM corrected = " << evt.blue_reference_vpt_div_pin_NIM_corrected_ << endl;
	    cout << "      integrated charge              = " << evt.integrated_charge_ << endl;
	    cout << "      date_temp                      = " << evt.date_temp_ << endl;
	    cout << "      time_temp                      = " << evt.time_temp_ << endl;
	    cout << "      elapsed time temp              = " << evt.elapsed_time_temp_ << endl;
	    cout << "      temperature vpt                = " << evt.temperature_vpt_ << endl;
	    cout << "      temperature pa                 = " << evt.temperature_pa_ << endl;
	    cout << "      temperature sa                 = " << evt.temperature_sa_ << endl;
	    if(vpt->run_num_==run_num::run2){
	      cout << "      temperature led                = " << evt.temperature_led_ << endl;
	      cout << "      temperature lab                = " << evt.temperature_lab_ << endl;
	    }
	    cout << "===============================================================================" << endl ;
	  }

 	} // end if run1


      } // end if site is Brunel


      //
      // Read in Raw Files For UVa
      //
      if(vpt->site_ == site::uva){
	
	raw_file >> evt.elapsed_time_;
	evt.elapsed_time_ /= 3600; // convert time to hours
	    
	//
	// Apologies for the necessary hard-coded corrections
	//  for operator mistakes in the timeOffset variable during runtime
	//
	// Run2 time corrections
	if(vpt->run_num_==run_num::run2){
	  if(evt.elapsed_time_ > 9.894973e6/3600 ) evt.elapsed_time_ += 5;
	}
	// Run3 time corrections
	if(vpt->run_num_==run_num::run3){
	  // Fix time offset
	  deltaTime     = evt.elapsed_time_- timeLast;
	  if(deltaTime<0) evt.elapsed_time_ = timeLast + deltaTimeLast;
	  deltaTimeLast = evt.elapsed_time_ - timeLast;
	  timeLast      = evt.elapsed_time_;
	}
	// Run4 time corrections
	if(vpt->run_num_==run_num::run4){
	  if(evt.elapsed_time_>263) evt.elapsed_time_ -= 530;
	}
	//
	// End of hard-coded time corrections
	//

	raw_file >> evt.rie_number_float_; 
	raw_file >> evt.angle_;
	
	if( (vpt->run_num_==run_num::run1) || (vpt->run_num_==run_num::run2) ){
	  raw_file >> evt.blue_reference_led_voltage_;
	}
	raw_file >> evt.blue_reference_led_frequency_;
	
	if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) ){
	  raw_file >> evt.orange_reference_led_frequency_;
	}

	if( (vpt->run_num_==run_num::run1) || (vpt->run_num_==run_num::run2) ){
	  raw_file >> evt.blue_load_led_voltage_; 
	}
	raw_file >> evt.blue_load_led_frequency_;
	raw_file >> evt.blue_load_led_isOn_;
	
	if( (vpt->run_num_==run_num::run1) || (vpt->run_num_==run_num::run2) ){
	  raw_file >> evt.blue_soak_led_voltage_;
	}
	raw_file >> evt.blue_soak_led_frequency_; 
	raw_file >> evt.blue_soak_led_isOn_; 
	
	raw_file >> evt.temperature_;
	raw_file >> evt.temperature_std_dev_;
	evt.temperature_err_ = evt.temperature_std_dev_/sqrt(25);

	raw_file >> evt.humidity_;
	raw_file >> evt.humidity_std_dev_;
	evt.humidity_err_ = evt.humidity_std_dev_/sqrt(25);

	raw_file >> evt.blue_load_cathode_current_raw_;
	raw_file >> evt.blue_load_cathode_current_raw_std_dev_;
	evt.blue_load_cathode_current_raw_err_ = evt.blue_load_cathode_current_raw_std_dev_/sqrt(5);

	if(evt.blue_load_cathode_current_raw_err_/evt.blue_load_cathode_current_raw_ > rel_err_thresh) evt.relative_err_filter_ = 0;

	raw_file >> evt.blue_load_pin_;
	raw_file >> evt.blue_load_pin_std_dev_;
	evt.blue_load_pin_err_ = evt.blue_load_pin_std_dev_/sqrt(1000);

	raw_file >> evt.blue_load_anode_raw_;
	raw_file >> evt.blue_load_anode_raw_std_dev_;
	evt.blue_load_anode_raw_err_ = evt.blue_load_anode_raw_std_dev_/sqrt(1000);
	
	raw_file >> evt.blue_reference_pin_;
	raw_file >> evt.blue_reference_pin_std_dev_;
	evt.blue_reference_pin_err_ = evt.blue_reference_pin_std_dev_/sqrt(1000);

	if(evt.blue_reference_pin_err_/evt.blue_reference_pin_ > rel_err_thresh) evt.relative_err_filter_ = 0;

	raw_file >> evt.blue_reference_anode_raw_;
	raw_file >> evt.blue_reference_anode_raw_std_dev_;	
	evt.blue_reference_anode_raw_err_ = evt.blue_reference_anode_raw_std_dev_/sqrt(1000);

	if(evt.blue_reference_anode_raw_err_/evt.blue_reference_anode_raw_ > rel_err_thresh) evt.relative_err_filter_ = 0;

	raw_file >> evt.blue_soak_pin_; 
	raw_file >> evt.blue_soak_pin_std_dev_;
	raw_file >> evt.blue_soak_anode_raw_;
	raw_file >> evt.blue_soak_anode_raw_std_dev_;
	
	raw_file >> evt.amp_vpt_in_;
	raw_file >> evt.amp_vpt_in_std_dev_;
	evt.amp_vpt_in_err_ = evt.amp_vpt_in_std_dev_/sqrt(2000);

	raw_file >> evt.amp_vpt_out_;
	raw_file >> evt.amp_vpt_out_std_dev_;
	evt.amp_vpt_out_err_ = evt.amp_vpt_out_std_dev_/sqrt(2000);

	raw_file >> evt.amp_pin_in_;
	raw_file >> evt.amp_pin_in_std_dev_;
	evt.amp_pin_in_err_ = evt.amp_pin_in_std_dev_/sqrt(2000);

	raw_file >> evt.amp_pin_out_;
	raw_file >> evt.amp_pin_out_std_dev_;      
	evt.amp_pin_out_err_ = evt.amp_pin_out_std_dev_/sqrt(2000);


	if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) ){
	  raw_file >> evt.blue_load_dark_cathode_current_;
	  raw_file >> evt.blue_load_dark_cathode_current_std_dev_;
	  evt.blue_load_dark_cathode_current_err_ = evt.blue_load_dark_cathode_current_std_dev_/sqrt(5);

	  raw_file >> evt.orange_reference_anode_raw_;
	  raw_file >> evt.orange_reference_anode_raw_std_dev_;
	  evt.orange_reference_anode_raw_err_ = evt.orange_reference_anode_raw_std_dev_/sqrt(1000);

	  if(evt.orange_reference_anode_raw_err_/evt.orange_reference_anode_raw_ > rel_err_thresh) evt.relative_err_filter_ = 0;

	  raw_file >> evt.orange_reference_pin_;
	  raw_file >> evt.orange_reference_pin_std_dev_;
	  evt.orange_reference_pin_err_ = evt.orange_reference_pin_std_dev_/sqrt(1000);
	  
	  if(evt.orange_reference_pin_err_/evt.orange_reference_pin_ > rel_err_thresh) evt.relative_err_filter_ = 0;

	}

	if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) && !(vpt->run_num_==run_num::run3) ){
	  raw_file >> evt.blue_reference_cathode_current_;
	  raw_file >> evt.blue_reference_cathode_current_std_dev_;
	  evt.blue_reference_cathode_current_err_ = evt.blue_reference_cathode_current_std_dev_/sqrt(5);
	
	  raw_file >> evt.orange_reference_cathode_current_;
	  raw_file >> evt.orange_reference_cathode_current_std_dev_;
	  evt.orange_reference_cathode_current_err_ = evt.orange_reference_cathode_current_std_dev_/sqrt(5);
	}


	if(verbose && entry_count<2){
	  cout << endl;
	  cout << "=====================================================================================" << endl ;
	  cout << "    Printing Variables Read In, -99.9=variable not filled, -1=NaN from data file..." << endl;
	  cout << "      time                           = " << evt.elapsed_time_ << endl;
	  cout << "      vpt num float                  = " << evt.rie_number_float_ << endl;
	  cout << "      angle                          = " << evt.angle_ << endl;
	  cout << "      led blue ref voltage           = " << evt.blue_reference_led_voltage_ << endl;
	  cout << "      led blue ref frequency         = " << evt.blue_reference_led_frequency_ << endl;
	  cout << "      led orange ref frequency       = " << evt.orange_reference_led_frequency_ << endl;
	  cout << "      led load voltage               = " << evt.blue_load_led_voltage_ << endl;
	  cout << "      led load frequency             = " << evt.blue_load_led_frequency_ << endl;
	  cout << "      led load isOn                  = " << evt.blue_load_led_isOn_ << endl;
	  cout << "      led soak voltage               = " << evt.blue_soak_led_voltage_ << endl;
	  cout << "      led soak frequency             = " << evt.blue_soak_led_frequency_ << endl;
	  cout << "      led soak isOn                  = " << evt.blue_soak_led_isOn_ << endl;
	  cout << "      temperature                    = " << evt.temperature_ << endl;
	  cout << "      temperature std dev            = " << evt.temperature_std_dev_ << endl;
	  cout << "      humidity                       = " << evt.humidity_ << endl;
	  cout << "      humidity std dev               = " << evt.humidity_std_dev_ << endl;
	  cout << "      blue load cathode              = " << evt.blue_load_cathode_current_raw_ << endl;
	  cout << "      blue load cathode std dev      = " << evt.blue_load_cathode_current_raw_std_dev_ << endl;
	  cout << "      blue load pin                  = " << evt.blue_load_pin_ << endl;
	  cout << "      blue load pin std dev          = " << evt.blue_load_pin_std_dev_ << endl;
	  cout << "      blue load anode                = " << evt.blue_load_anode_raw_ << endl;
	  cout << "      blue load anode std dev        = " << evt.blue_load_anode_raw_std_dev_ << endl;
	  cout << "      blue ref pin                   = " << evt.blue_reference_pin_ << endl;
	  cout << "      blue ref pin std dev           = " << evt.blue_reference_pin_std_dev_ << endl;
	  cout << "      blue ref anode                 = " << evt.blue_reference_anode_raw_ << endl;
	  cout << "      blue ref anode std dev         = " << evt.blue_reference_anode_raw_std_dev_ << endl;
	  cout << "      soak pin                       = " << evt.blue_soak_pin_ << endl;
	  cout << "      soak pin std dev               = " << evt.blue_soak_pin_std_dev_ << endl;
	  cout << "      soak anode                     = " << evt.blue_soak_anode_raw_ << endl;
	  cout << "      soak anode std dev             = " << evt.blue_soak_anode_raw_std_dev_ << endl;
	  cout << "      amp vpt input                  = " << evt.amp_vpt_in_ << endl;
	  cout << "      amp vpt input std dev          = " << evt.amp_vpt_in_std_dev_ << endl;
	  cout << "      amp vpt out                    = " << evt.amp_vpt_out_ << endl;
	  cout << "      amp vpt out std dev            = " << evt.amp_vpt_out_std_dev_ << endl;
	  cout << "      amp pin input                  = " << evt.amp_pin_in_ << endl;
	  cout << "      amp pin input std dev          = " << evt.amp_pin_in_std_dev_ << endl;
	  cout << "      amp pin output                 = " << evt.amp_pin_out_ << endl;
	  cout << "      amp pin output std dev         = " << evt.amp_pin_out_std_dev_ << endl;
	  cout << "      blue load dark current         = " << evt.blue_load_dark_cathode_current_ << endl;
	  cout << "      blue load dark current std dev = " << evt.blue_load_dark_cathode_current_std_dev_ << endl;
	  cout << "      orange ref anode               = " << evt.orange_reference_anode_raw_ << endl;
	  cout << "      orange ref anode std dev       = " << evt.orange_reference_anode_raw_std_dev_ << endl;
	  cout << "      orange ref pin                 = " << evt.orange_reference_pin_ << endl;
	  cout << "      orange ref pin std dev         = " << evt.orange_reference_pin_std_dev_ << endl;
	  cout << "      blue ref cathode               = " << evt.blue_reference_cathode_current_ << endl;
	  cout << "      blue ref cathode std dev       = " << evt.blue_reference_cathode_current_std_dev_ << endl;
	  cout << "      orange ref cathode             = " << evt.orange_reference_cathode_current_ << endl;
	  cout << "      orange ref cathode std dev     = " << evt.blue_reference_cathode_current_std_dev_ << endl;
	  cout << "      relative error filter          = " << evt.relative_err_filter_ << endl;
	  cout << "====================================================================================" << endl << endl ;

	} // end verbose print statement

	  
      } // end if site is UVa

      //
      // Perform Offset Corrections
      //
      vpt->get_offset_corrections(evt);
	 
      // Fill Branch
      tree->Fill();

    } // end loop over raw data file entries

    // Reset Utility Vars
    timeLast=0; deltaTime=0; deltaTimeLast=0;
    
    // Close raw data file
    raw_file.close();
    if(vpt->site_==site::brunel && vpt->run_num_==run_num::run1) raw_file_2.close();
    
    // Reset branch address
    tree->Write(vpt->tree_name_, TObject::kOverwrite);
    tree->ResetBranchAddresses();

  } // end loop of raw data files
  
  // Associate all trees in the same run with one another as friends
  make_friends();

  return;
}

//_____________________________________________________________________________
//
// Make friends for TTrees in the same run and at the same site
//
void vpt_analysis::make_friends(){

  bool verbose = false;

  if(verbose) cout << "  Making tree friends..." << endl;

  for(vector<vptInfo*>::const_iterator tIter1 = vpt_list_.begin(); tIter1 != vpt_list_.end(); ++tIter1){
 
    vptInfo *vpt1 = *tIter1;
    
    TTree *t1 = (TTree*)data_file_->Get(vpt1->tree_name_.Data());

    site::site          site1 = vpt1->site_;
    run_num::run_num run_num1 = vpt1->run_num_;

    for(vector<vptInfo*>::const_iterator tIter2 = vpt_list_.begin(); tIter2 != vpt_list_.end(); ++tIter2){

      vptInfo *vpt2 = *tIter2;

      site::site          site2 = vpt2->site_;
      run_num::run_num run_num2 = vpt2->run_num_;

      if(vpt1==vpt2) continue;
     
      if(site1!=site2)       continue;
      if(run_num1!=run_num2) continue;
     
      t1->AddFriend(vpt2->tree_name_);
     
    } // end inner loop over vpts

  } // end outer loop over vpts
   
  return;
}


//_____________________________________________________________________________
//
// Calculate Dark Current 
//
void vpt_analysis::get_extrapolated_dark_current(){

  cout << "  Calculating Extrapolated Dark Current..." << endl;

  // For Use in Debugging
  bool verbose = false;

  // Loop over raw data files and fill root file
  for(std::vector<vptInfo*>::const_iterator tIter = vpt_list_.begin(); tIter != vpt_list_.end(); ++tIter){
    
    vptInfo *vpt = *tIter; // ptr to iterator

    if(verbose) cout << "    For VPT: " << vpt->raw_data_file_ << endl;;

    if(vpt->site_==site::brunel) continue;

    //if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) && !(vpt->run_num_==run_num::run3) ) continue;
    if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) ) continue;


    TTree *tree = (TTree*)data_file_->Get(vpt->tree_name_.Data());

    //
    // Set Unused Branches to Status 0
    //
    tree->SetBranchStatus("*",                                 0);
    tree->SetBranchStatus("blue_load_led_frequency",           1);
    tree->SetBranchStatus("blue_load_pin",                     1);
    tree->SetBranchStatus("blue_load_cathode_current_raw",     1);
    tree->SetBranchStatus("blue_load_cathode_current_raw_err", 1);
    tree->SetBranchStatus("elapsed_time",                      1);


    // Create branch on ttree
    TBranch *dc;
    TBranch *dc_err;

    measurement evt;
    initialize(evt);

    //
    // Create new Branches
    //
    if( (vpt->run_num_==run_num::run1) || (vpt->run_num_==run_num::run2) ){
      dc     = tree->Branch("blue_load_dark_cathode_current",     &evt.blue_load_dark_cathode_current_,     "blue_load_dark_cathode_current/F");
      dc_err = tree->Branch("blue_load_dark_cathode_current_err", &evt.blue_load_dark_cathode_current_err_, "blue_load_dark_cathode_current_err/F");
    }
    else{
      dc     = tree->Branch("blue_load_extrapolated_dark_cathode_current",     &evt.blue_load_dark_cathode_current_,    "blue_load_extrapolated_dark_cathode_current/F");
      dc_err = tree->Branch("blue_load_extrapolated_dark_cathode_current_err", &evt.blue_load_dark_cathode_current_err_,"blue_load_extrapolated_dark_cathode_current_err/F");
    }

    //
    // Get relevent variables for calculation
    //
    TString vars = "blue_load_led_frequency";
    vars        += ":";
    vars        += "blue_load_pin";
    vars        += ":";
    vars        += "blue_load_cathode_current_raw";
    vars        += ":";
    vars        += "blue_load_cathode_current_raw_err";
    vars        += ":";
    vars        += "elapsed_time";

    tree->Draw(vars,"","para goff");
    Double_t *load_led_frequency  = tree->GetVal(0);
    Double_t *load_pin            = tree->GetVal(1);
    Double_t *cathode_current     = tree->GetVal(2);
    Double_t *cathode_current_err = tree->GetVal(3);
    Double_t *elapsed_time        = tree->GetVal(4);

    // Other Variables
    bool found_first_dark_region=false;

    int numPtsBack  = 10;
    int numPtsForw  = 10;

    double fit1_time_begin=0, fit1_time_end=0;
    double fit2_time_begin=0, fit2_time_end=0;
    double chiSq1=999, chiSq2=999;

    int iFit=0;
    // Loop over entries and calculate dark current
    int nEntries = tree->GetEntries(); 
    for(int i=0; i<nEntries; i++){

      //
      // Initialize blue_load_dark_current_(err_) == -99.9
      //
      initialize(evt);

      // Save time and only calculate after run_begin_
      if(elapsed_time[i] < vpt->run_begin_){ 
	dc->Fill();  // Fill dark current branch
	dc_err->Fill();
	continue;
      }

      // DMM Cannot meaure currents less than ~100 picoamps, 500 is an ~ threshold
      if(load_led_frequency[i] < 500){
	evt.blue_load_dark_cathode_current_     = cathode_current[i];
	evt.blue_load_dark_cathode_current_err_ = cathode_current_err[i];
	found_first_dark_region = true;
	dc->Fill();   // Fill dark current branch
	dc_err->Fill(); 
	continue;
      }

      // Actual dark current
      if(load_pin[i] < 0){
	evt.blue_load_dark_cathode_current_     = cathode_current[i];
	evt.blue_load_dark_cathode_current_err_ = cathode_current_err[i];
	found_first_dark_region = true;
	dc->Fill();  // Fill dark current branch
	dc_err->Fill();
	continue;
      }
     
      // Can't extrapolate until have passed one dark current region
      if(load_pin[0]>0 && !found_first_dark_region){ 
	dc->Fill();  // Fill dark current branch
	dc_err->Fill();
	continue;
      }

      //
      // Now, we have found our first section we can extrapolate in
      //
      
      // Get an array of points backwards
      deque<double> dark_cathode, dark_cathode_err, time;
      for(int j=i-1; j>i-numPtsBack-1; j--){
	time.push_front(elapsed_time[j]);
	dark_cathode.push_front(cathode_current[j]);
	dark_cathode_err.push_front(cathode_current_err[j]);
      }
      fit1_time_begin = time[(int)time.size()-2];
      fit2_time_begin = time[0];

      // Look Forward until found next dark current region
      int count=i+1;
      bool foundEnd = false;
      while(count<nEntries && !foundEnd){
	
	// But, if there aren't enough points, then can't findEnd
	if(count+numPtsForw >= nEntries) break;
       
	// The next few entries will have the load light on
	if(load_pin[count]>0){
	  count++;  // Keep looking
	  continue;
	} 
	  
	// At this point, have found next dark region, get next points
	for(int j=count; j<count+numPtsForw; j++){
	  time.push_back(elapsed_time[j]);
	  dark_cathode.push_back(cathode_current[j]);
	  dark_cathode_err.push_back(cathode_current_err[j]);
	}
	foundEnd = true;

      } // end while looking for next dark region
      fit1_time_end = time[(int)time.size()-(numPtsForw-2)];
      fit2_time_end = time[(int)time.size()-1];


      // If no upcoming dark current, fill the rest of the entries and break
      if(!foundEnd){
	for(int j=i; j<nEntries; j++){
	  dc->Fill();
	  dc_err->Fill();
	}
	break;  // break loop over entries
      }
    
      const int nPts = (int)time.size();
      Float_t *graph_pts_y     = new Float_t[nPts];
      Float_t *graph_pts_y_err = new Float_t[nPts];
      Float_t *graph_pts_x     = new Float_t[nPts];
      Float_t *graph_pts_x_err = NULL;
      for(int j=0; j<nPts; j++){
	graph_pts_x[j]     = time[j];
	graph_pts_y[j]     = dark_cathode[j];
	graph_pts_y_err[j] = dark_cathode_err[j];
      }
      TGraphErrors *gr1 = new TGraphErrors(nPts, graph_pts_x, graph_pts_y, graph_pts_x_err, graph_pts_y_err);
      
      // Get difference in endpoints for error
      double endPtDiff = fabs(gr1->GetY()[gr1->GetN()-1] - gr1->GetY()[0]);

      // Fit Polynomials, "NQ" = "No draw, Quiet mode (no printing)"
      TF1 *fit1 = new TF1("fit1", "pol1", fit1_time_begin, fit1_time_end);
      gr1->Fit("fit1","NQ");
      chiSq1 = fit1->GetChisquare();
        
      TF1 *fit2 = new TF1("fit2", "pol2", fit2_time_begin, fit2_time_end);
      gr1->Fit("fit2","NQ");
      chiSq2 = fit2->GetChisquare();

      iFit++;

      // Diagnostic Print Statements
      if(verbose && iFit%50==0){
	cout << endl;
	cout << "      ==================================" << endl;
	cout << "      Fit Number        = " << iFit << endl;
	cout << "      Poly1 Time Period = [";
	cout << fit1_time_begin << ", " << fit1_time_end << "]"<< endl;
	cout << "      Poly2 Time Period = [";
	cout << fit2_time_begin << ", " << fit2_time_end << "]"<< endl;
	cout << "        Chi Sq pol1     = " << chiSq1 << endl;
	cout << "        Chi Sq pol2     = " << chiSq2 << endl;
	cout << "      ==================================" << endl;
	cout << endl;
      }

      // Extrapolate dark current when load light on
      for(int j=i; j<nEntries; j++){
	if(load_pin[j] < 0){ // If find next dark region, extrapolation is done
	  i=j-1; // set nEntries counter to pnt just before next dark region
	  break;
	}
	
	evt.blue_load_dark_cathode_current_     = 0;
	evt.blue_load_dark_cathode_current_err_ = endPtDiff/2.0;

	// If quadratic is best
	if(chiSq2<chiSq1*1.2 && chiSq2!=0){
	  for(int k=0; k<3; k++){
	    evt.blue_load_dark_cathode_current_ += pow(elapsed_time[j],k)*fit2->GetParameter(k);
	  }
	}
	// If linear fit is best
	else{
	  if(chiSq1!=0){ 
	    for(int k=0; k<2; k++){
	      evt.blue_load_dark_cathode_current_ += pow(elapsed_time[j],k)*fit1->GetParameter(k);
	    }
	  } // end if lin fit successful
	} // end if lin fit is best 
	
	dc->Fill();   // Fill dark current branch
	dc_err->Fill();
	gr1->~TGraphErrors(); // Destroy TGraphErrors now that we are done
       
      } // end extrapolation of dark current 
  
    } // end loop over entries
  
    tree->SetBranchStatus("*", 1);
    tree->Write(vpt->tree_name_, TObject::kOverwrite);
    tree->ResetBranchAddresses();
  }

  return;
}


//_____________________________________________________________________________
//
// Get Corrections to the PIN responses
//
void vpt_analysis::get_pin_corrections(){
  
  cout << "  Calculating Corrected PIN Responses..." << endl;

  bool verbose = false;

  // Loop over raw data files and fill root file
  for(std::vector<vptInfo*>::const_iterator tIter = vpt_list_.begin(); tIter != vpt_list_.end(); ++tIter){
    
    vptInfo *vpt = *tIter; // ptr to iterator

    bool hasOrangeData = (vpt->site_==site::uva && ( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) ) );

    TTree *tree = (TTree*)data_file_->Get(vpt->tree_name_.Data());
    
    tree->SetBranchStatus("*",            0);
    tree->SetBranchStatus("*pin",         1);
    tree->SetBranchStatus("*pin*",        1);
    tree->SetBranchStatus("elapsed_time", 1);

    measurement evt;
    initialize(evt);
    
    TBranch *b_blue_ref_pin_cor     = tree->Branch( "blue_reference_pin_correction",     &evt.blue_reference_pin_correction_,     "blue_reference_pin_correction/F");
    TBranch *b_blue_ref_pin_cor_err = tree->Branch( "blue_reference_pin_correction_err", &evt.blue_reference_pin_correction_err_, "blue_reference_pin_correction_err/F");
    TBranch *b_blue_load_pin_cor=NULL, *b_blue_load_pin_cor_err=NULL;
    TBranch *b_orng_ref_pin_cor=NULL,  *b_orng_ref_pin_cor_err=NULL;
    
    if(vpt->site_ == site::uva){
      b_blue_load_pin_cor      = tree->Branch( "blue_load_pin_correction",     &evt.blue_load_pin_correction_,     "blue_load_pin_correction/F");
      b_blue_load_pin_cor_err  = tree->Branch( "blue_load_pin_correction_err", &evt.blue_load_pin_correction_err_, "blue_load_pin_correction_err/F");
      
      if(hasOrangeData){
	b_orng_ref_pin_cor     = tree->Branch( "orange_reference_pin_correction",     &evt.orange_reference_pin_correction_,     "orange_reference_pin_correction/F");
	b_orng_ref_pin_cor_err = tree->Branch( "orange_reference_pin_correction_err", &evt.orange_reference_pin_correction_err_, "orange_reference_pin_correction_err/F");
      }
     }
    
    // Vector to hold different PIN types
    vector<TString> pin_branch;
    pin_branch.push_back("blue_reference_pin");
    if(vpt->site_==site::uva){
      pin_branch.push_back("blue_load_pin");
      if(hasOrangeData) pin_branch.push_back("orange_reference_pin");
    }

    
    // Loop over pin_branch vector to form TString for pin corrections
    for(int iPin=0; iPin<(int)pin_branch.size(); iPin++){

      TString pin_str="", pin_err_str="";
      for(int iFriend=0; iFriend<(int)vpt->friend_trees_.size(); iFriend++){
	if(iFriend==0){
	  pin_str     += "( (";
	  pin_err_str += "( sqrt( ";
	}
	else{
	  pin_str     += " + ";
	  pin_err_str += " + ";
	}
	
	pin_str     += vpt->friend_trees_[iFriend];
	pin_str     += ".";
	pin_str     += pin_branch[iPin];
	
	pin_err_str += "pow(";
	pin_err_str += vpt->friend_trees_[iFriend];
	pin_err_str += ".";
	pin_err_str += pin_branch[iPin];
	pin_err_str += "_err";
	pin_err_str += ", 2)";

      } // end loop over friend trees

      pin_str    += ")/";
      pin_str    += (int)vpt->friend_trees_.size();
      pin_str    += ".0 )";
       
      pin_err_str += " )/";
      pin_err_str += (int)vpt->friend_trees_.size();
      pin_err_str += ".0 )";

      if((int)vpt->friend_trees_.size()==0){
	pin_str     = pin_branch[iPin];
	pin_err_str = pin_branch[iPin] + "_err";
      }

      int nEntries = (int)tree->GetEntries();

      //
      // Get Pin Normalization
      //
      TString draw_this = "";

      draw_this = pin_str + ":" + pin_err_str + ":elapsed_time";
      tree->Draw(draw_this, "", "goff");
      Double_t *pin     = tree->GetV1();
      Double_t *pin_err = tree->GetV2();
      Double_t *time    = tree->GetV3();
       
      double pinNorm=0.0, pinNorm_err=0.0;
      double pinNorm_tot=0.0, pinNorm_tot_err=0.0;
      int pinNorm_cnt=0, pinNorm_tot_cnt=0.0;
      int numToAvg=10;

      // Get pin normalizations
      //  Should be a constant for Blue/Orange Reference LED
      //  Since Load LED changes during run, only use err in small region 
      for(int i=0; i<nEntries; i++){
	if( (time[i]>=vpt->run_begin_) && (pin[i]>0) ){
      	  // Get pin norm in a small region near beginnning of run time
	  if( pinNorm_cnt<numToAvg ){
	    pinNorm     += pin[i];
	    pinNorm_err += pow( pin_err[i], 2);
	    pinNorm_cnt++; 
	  }
	  // Get pin norm over entire run
	  pinNorm_tot += pin[i];
	  pinNorm_tot_cnt++;
 	} // end if pin>0
      } // end loop over entries

      // Check that actually found points - default norm is first entry
      if(pinNorm_cnt==0){
	cout << "      PIN NORMALIZATION ERROR - " << vpt->tree_name_ << ", " << pin_branch[iPin] << endl;
	pinNorm         = pin[0];
	pinNorm_tot_err = pin_err[0];
      }
      // Complete Normalization calculation
      else{
	pinNorm     /= pinNorm_cnt;
	pinNorm_tot /= pinNorm_tot_cnt;

	// Load LED varies with frequency - calc. error from beggning region
	if(pin_branch[iPin]=="blue_load_pin"){
	  pinNorm_tot_err  = sqrt(pinNorm_err);
	  pinNorm_tot_err /= pinNorm_cnt;
	}
	// Complete Calculation for Blue/Orange LEDs
	else{
	  // Since we have small values, too risky to calc std dev with one loop method
	  for(int i=0; i<nEntries; i++){
	    if( (time[i]>=vpt->run_begin_) && (pin[i]>0) ){
	      pinNorm_tot_err += pow( pin[i] - pinNorm_tot, 2 ); 
	    }
	  }
	  pinNorm_tot_err /= pinNorm_tot_cnt;
	  pinNorm_tot_err  = sqrt(pinNorm_tot_err);
	}
      }

      if(verbose || pinNorm_cnt==0){
	cout << "      " << pin_branch[iPin] << "  Expression        = " << pin_str << endl;
	cout << "      " << pin_branch[iPin] << "  Err Expression    = " << pin_err_str << endl;
	cout << "      " << pin_branch[iPin] << "  Normalization     = " << pinNorm << endl;
	cout << "      " << pin_branch[iPin] << "  Normalization Err = " << pinNorm_tot_err << "(" << pinNorm_tot_err*100/pinNorm_tot << "%)" << endl;
	cout << endl;
      }

      //
      // Calculate PIN correction for iPin
      //
      for(int i=0; i<nEntries; i++){
      
	// PIN corection
	double pinCorrection     = 1.0;
	double pinCorrection_err = 0.0;
	if(pin[i]>0){
	  pinCorrection      = pinNorm/pin[i];
	 
	  pinCorrection_err  = pow( pinNorm_tot_err/pinNorm_tot, 2); // Systematic Error on Norm
	  pinCorrection_err += pow( pin_err[i]/pin[i], 2);           // Statistical Error on Norm
	  pinCorrection_err  = sqrt(pinCorrection_err);
	  pinCorrection_err *= pinCorrection;
	}	
	
	if(pin_branch[iPin]=="blue_reference_pin"){
	  evt.blue_reference_pin_correction_     = pinCorrection;
	  evt.blue_reference_pin_correction_err_ = pinCorrection_err;
	  b_blue_ref_pin_cor->Fill();
	  b_blue_ref_pin_cor_err->Fill();
	}
	
	if(pin_branch[iPin]=="blue_load_pin"){
	  evt.blue_load_pin_correction_     = pinCorrection;
	  evt.blue_load_pin_correction_err_ = pinCorrection_err;
	  b_blue_load_pin_cor->Fill();
	  b_blue_load_pin_cor_err->Fill();
	}

	if(pin_branch[iPin]=="orange_reference_pin"){
	  evt.orange_reference_pin_correction_     = pinCorrection;
	  evt.orange_reference_pin_correction_err_ = pinCorrection_err;
	  b_orng_ref_pin_cor->Fill();
	  b_orng_ref_pin_cor_err->Fill();
	}
	
      } // end loop over entries

    } // end loop over PINs to correction


    // Reset Branch Addresses
    tree->SetBranchStatus("*", 1);
    tree->Write(vpt->tree_name_, TObject::kOverwrite);
    tree->ResetBranchAddresses();
    
  } // end loop over VPTs


  return;

}

//_____________________________________________________________________________
//
// Get Corrections to the cathode current
//
void vpt_analysis::get_cathode_corrections(){
  
  cout << "  Calculating Corrected Cathode Current..." << endl;

  bool verbose = false;

  // Loop over raw data files and fill root file
  for(std::vector<vptInfo*>::const_iterator tIter = vpt_list_.begin(); tIter != vpt_list_.end(); ++tIter){
    
    vptInfo *vpt = *tIter; // ptr to iterator

     TTree *tree = (TTree*)data_file_->Get(vpt->tree_name_.Data());

     if(verbose) cout << "    For VPT: " << vpt->tree_name_ << endl;

     tree->SetBranchStatus("*",                   0);
     if(vpt->site_==site::uva){
       tree->SetBranchStatus("blue_load*cathode*",  1);
       tree->SetBranchStatus("blue_load_pin_corr*", 1);
       tree->SetBranchStatus("elapsed_time",        1);
     }
     if(vpt->site_==site::brunel){
       tree->SetBranchStatus("elapsed_time",        1);
       tree->SetBranchStatus("integrated_charge",   1);
     }

     measurement evt;
     initialize(evt);

     TBranch *b_cc        = tree->Branch( "blue_load_cathode_current",               &evt.blue_load_cathode_current_,               "blue_load_cathode_current/F");
     TBranch *b_cc_err    = tree->Branch( "blue_load_cathode_current_err",           &evt.blue_load_cathode_current_err_,           "blue_load_cathode_current_err/F");
     TBranch *b_cc_pp     = tree->Branch( "blue_load_cathode_current_per_pulse",     &evt.blue_load_cathode_current_per_pulse_,     "blue_load_cathode_current_per_pulse/F");
     TBranch *b_cc_pp_err = tree->Branch( "blue_load_cathode_current_per_pulse_err", &evt.blue_load_cathode_current_per_pulse_err_, "blue_load_cathode_current_per_pulse_err/F");

     double dmm_apperature = 0.1; // 100 ms apperature for PXI DMM

     // Integrated charge only stored for Brunel, extapolate cathode current
     if(vpt->site_==site::brunel){

       tree->Draw("elapsed_time:integrated_charge","","goff");
       Double_t *elapsed_time      = tree->GetV1();
       Double_t *integrated_charge = tree->GetV2();

       int nEntries = (int)tree->GetEntries();
       double timeLast=0, intQLast=0;
       for(int i=0; i<nEntries; i++){
	 
	 initialize(evt);

	 if(i==0){
	   timeLast = elapsed_time[i];
	   intQLast = integrated_charge[i];
	   
	   b_cc->Fill();
	   b_cc_err->Fill();
	   b_cc_pp->Fill();
	   b_cc_pp_err->Fill();
	   
	   continue;
	 }
	 else{
	
	   evt.blue_load_cathode_current_               = (integrated_charge[i] - intQLast) / (elapsed_time[i] - timeLast);
	   evt.blue_load_cathode_current_err_           = 0.01*evt.blue_load_cathode_current_;                       // Assuming 1% error
	   evt.blue_load_cathode_current_per_pulse_     = evt.blue_load_cathode_current_ / ( 10000*dmm_apperature ); // Assuming 10kHz load rate!!
	   evt.blue_load_cathode_current_per_pulse_err_ = 0.01*evt.blue_load_cathode_current_per_pulse_ / ( 10000*dmm_apperature );

	   timeLast = elapsed_time[i];
	   intQLast = integrated_charge[i];

	   b_cc->Fill();
	   b_cc_err->Fill();
	   b_cc_pp->Fill();
	   b_cc_pp_err->Fill();
	   
	   continue;
	
	 }
	 
       } // end loop over entries
       
     } // end case where site is Brunel  
     

     // Use Dark Current and Load Pin Measurments to Correct Cathode Current
     if(vpt->site_==site::uva){

       TString vars = "";
       vars += "blue_load_cathode_current_raw";
       vars += ":";
       vars += "blue_load_cathode_current_raw_err";
       vars += ":";
       vars += "blue_load_dark_cathode_current";
       vars += ":";
       vars += "blue_load_dark_cathode_current_err";
       //vars += ":";
       //vars += "blue_load_pin_correction";
       //vars += ":";
       //vars += "blue_load_pin_correction_err";
       
       tree->Draw(vars, "", "para goff");
       Double_t *cathode_current         = tree->GetVal(0);
       Double_t *cathode_current_err     = tree->GetVal(1);
       Double_t *dark_current            = tree->GetVal(2);
       Double_t *dark_current_err        = tree->GetVal(3);
       //Double_t *load_pin_correction     = tree->GetVal(4);
       //Double_t *load_pin_correction_err = tree->GetVal(5);

       int nEntries = (int)tree->GetEntries();

       //
       // Calculate Cathode Current Corrections
       //
       for(int i=0; i<nEntries; i++){
	 
	 initialize(evt);
	 
	 // Simple Cathode Filter
	 if( (cathode_current[i] > 40e-9) || (cathode_current[i] < -1e-9) ){
	   b_cc->Fill();
	   b_cc_err->Fill();
	   b_cc_pp->Fill();
	   b_cc_pp_err->Fill();

	   continue;
	 }
	 
	 // Dark Current Subtraction
	 evt.blue_load_cathode_current_               = cathode_current[i];
	 evt.blue_load_cathode_current_err_           = cathode_current_err[i];

	 if(dark_current[i] > -1.0){
	   evt.blue_load_cathode_current_             = cathode_current[i] - dark_current[i];
	   evt.blue_load_cathode_current_err_         = sqrt( pow(cathode_current_err[i], 2) + pow(dark_current_err[i], 2) );
	 }
	 
	 evt.blue_load_cathode_current_per_pulse_     = evt.blue_load_cathode_current_/( evt.blue_load_led_frequency_ * dmm_apperature );
	 evt.blue_load_cathode_current_per_pulse_err_ = evt.blue_load_cathode_current_err_/( evt.blue_load_led_frequency_ * dmm_apperature );
      
	 
	 // Load PIN corection
	 //double pinCorrectionX2                    = (load_pin_correction[i]-1)*2 + 1;
	 //double cathode_current_no_pin_correction  = evt.blue_load_cathode_current_;
	 //evt.blue_load_cathode_current_           *= load_pin_correction[i];
	 
	 //double cathode_err_temp  = pow(evt.blue_load_cathode_current_err_ / evt.blue_load_cathode_current_, 2);
	 //cathode_err_temp        += pow(load_pin_correction_err[i] / load_pin_correction[i], 2);
	 //cathode_err_temp         = sqrt(cathode_err_temp);
	 //cathode_err_temp        *= cathode_current[i];

	 // For error compare propagated error, to error based on no correction to x2 correction
	 //double diff_noCorrection = fabs(cathode_current_no_pin_correction - evt.blue_load_cathode_current_);
	 //double diff_x2Correction = fabs(cathode_current_no_pin_correction - cathode_current_no_pin_correction*pinCorrectionX2);
	 
	 //double err_temp = 0.0;
	 //err_temp = std::max( err_temp, diff_noCorrection );
	 //err_temp = std::max( err_temp, diff_x2Correction );
	 //err_temp = std::max( err_temp, cathode_err_temp );
	 
	 //evt.blue_load_cathode_current_err_           = err_temp;
	 //evt.blue_load_cathode_current_err_           = cathode_err_temp;
	 //evt.blue_load_cathode_current_per_pulse_     = evt.blue_load_cathode_current_/( evt.blue_load_led_frequency_ * dmm_apperature );
	 //evt.blue_load_cathode_current_per_pulse_err_ = evt.blue_load_cathode_current_err_/( evt.blue_load_led_frequency_ * dmm_apperature );
	 
	 if(verbose && i%10000==0){
	   cout << "      Cathode Current Raw    = " << cathode_current[i] << endl;
	   cout << "      Dark Cathode Current   = " << dark_current[i] << endl;
	   cout << "      Cathode - Dark Current = " << cathode_current[i] - dark_current[i] << endl;
	   //cout << "      Load PIN Correction    = " << load_pin_correction[i] << endl;
	   cout << "      Final Cathode Current  = " << evt.blue_load_cathode_current_ << endl;
	   cout << endl << endl;
	 }
	 
	 b_cc->Fill();
	 b_cc_err->Fill();
	 b_cc_pp->Fill();
	 b_cc_pp_err->Fill();	

       } // end loop over entries

     } // end if site is UVa

     tree->SetBranchStatus("*", 1);
     tree->Write(vpt->tree_name_, TObject::kOverwrite);
     tree->ResetBranchAddresses();
     
  }

  return;
}


//_____________________________________________________________________________
// 
// Integrate Charge
void vpt_analysis::get_integrated_charge(){

  cout << "  Calculating Integrated Charge..." << endl;
 
  bool verbose = false;

  // Loop over raw data files and fill root file
  for(std::vector<vptInfo*>::const_iterator tIter = vpt_list_.begin(); tIter != vpt_list_.end(); ++tIter){
    
    vptInfo *vpt = *tIter; // ptr to iterator
    
    if(vpt->site_==site::brunel) continue;
      
    if(verbose) cout << "    For VPT: " << vpt->tree_name_ << endl;

    TTree *tree = (TTree*)data_file_->Get(vpt->tree_name_.Data());

    // Get branches to help calculate dark current
    tree->SetBranchStatus("*",                             0);
    tree->SetBranchStatus("blue_load_cathode_current",     1);
    tree->SetBranchStatus("blue_load_cathode_current_err", 1);
    tree->SetBranchStatus("blue_load_led_frequency",       1);
    tree->SetBranchStatus("blue_load_pin",                 1);
    tree->SetBranchStatus("elapsed_time",                  1);

    // Create branch on ttree
    measurement evt;
    initialize(evt);

    TBranch *b_intQ     = tree->Branch("integrated_charge",     &evt.integrated_charge_,     "integrated_charge/F");
    TBranch *b_intQ_err = tree->Branch("integrated_charge_err", &evt.integrated_charge_err_, "integrated_charge_err/F");

    TString vars = "";
    vars += "blue_load_cathode_current";
    vars += ":";
    vars += "blue_load_cathode_current_err";
    vars += ":";
    vars += "blue_load_led_frequency";
    vars += ":";
    vars += "blue_load_pin";
    vars += ":";
    vars += "elapsed_time";
    
    tree->Draw(vars, "", "para goff");
    Double_t *cathode_current     = tree->GetVal(0);
    Double_t *cathode_current_err = tree->GetVal(1);
    Double_t *load_led_frequency  = tree->GetVal(2);
    Double_t *load_pin            = tree->GetVal(3);
    Double_t *elapsed_time        = tree->GetVal(4);

    int nEntries = tree->GetEntries();
    double intQ_temp=0.0, intQ_err_temp=0.0;
    for(int i=0; i<nEntries; i++){
      
      if(i==0) continue;

      initialize(evt);

      if(verbose && i%10000==0){
	cout << "      ==================================" << endl;
	cout << "      Begin Run Time     = " << vpt->run_begin_ << endl;
	cout << "      Elapsed Time       = " << elapsed_time[i] << endl;
	cout << "      LED Frequency      = " << load_led_frequency[i] << endl;
	cout << "      Load LED PIN       = " << load_pin[i] << endl;
	cout << "      Cathode Curent     = " << cathode_current[i] << endl;
      }

      if( elapsed_time[i] < vpt->run_begin_ ){
	if(verbose && i%10000==0){
	  cout << "      VETOED BY TIME<RUN_BEGIN" << endl;
	  cout << "      ==================================" << endl << endl;
	}
	b_intQ->Fill();
	b_intQ_err->Fill();
	continue;
      }

      if( cathode_current[i]    <= -1                   || 
	  cathode_current_err[i]/cathode_current[i] > 1 ||
	  load_led_frequency[i] <  500                  ||
	  load_pin[i]           <  0                       ){
	if(verbose && i%10000==0){
	  cout << "      VETOED BAD CATHODE OR LED<500Hz" << endl;
	  cout << "      ==================================" << endl << endl;
	}
	b_intQ->Fill();
	b_intQ_err->Fill();
	continue;
      }

      // Check if last entry had the load light off
      if(load_pin[i-1] < 0){
	if(verbose && i%10000==0){
	  cout << "      VETOED BY LAST ENTRY BEING OFF" << endl;
	  cout << "      ==================================" << endl << endl;
	}
	b_intQ->Fill();
	b_intQ_err->Fill();
	continue;
      }
      double lastTime = elapsed_time[i-1];

      if(verbose && i%10000==0){
	cout << "      Last Time          = " << lastTime << endl;
	cout << "      Delta Time         = " << elapsed_time[i] - lastTime << endl;
      }

      // Check if delta time is unreasonably large or negative
      if( ((elapsed_time[i]-lastTime)>1) || ((elapsed_time[i]-lastTime)<0) ){
	if(verbose && i%10000==0){
	  cout << "      VETOED BY LAST ENTRY TIME" << endl;
	  cout << "      ==================================" << endl << endl;
	}
	b_intQ->Fill();
	b_intQ_err->Fill();
	continue;
      }
    
      double increment = 3600*(elapsed_time[i]-lastTime)*cathode_current[i];
      if(increment<0){
	if(verbose && i%10000==0){
	  cout << "      VETOED BY INCREMENT<0" << endl;
	  cout << "      ==================================" << endl << endl;
	}
	b_intQ->Fill();
	b_intQ_err->Fill();
	continue;
      }
      
      //
      // Increment intQ and set error
      //
      intQ_temp                 += increment;
      evt.integrated_charge_     = intQ_temp;
      intQ_err_temp              = intQ_temp*cathode_current_err[i]/cathode_current[i];
      evt.integrated_charge_err_ = intQ_err_temp;

      if(verbose && i%10000==0){
	cout << "      IntQ Increment     = " << increment << endl;
	cout << "      Running Total      = " << intQ_temp << endl;
	cout << "      ==================================" << endl << endl;
      }

      b_intQ->Fill();
      b_intQ_err->Fill();
      
    } // end loop over entries
    
    if(verbose){
      cout << endl;
      cout << "      Total IntQ For " << vpt->tree_name_;
      cout << " = " << intQ_temp << " +/- " << intQ_err_temp;
      cout << endl << endl;
    }

    tree->SetBranchStatus("*", 1);
    tree->Write(vpt->tree_name_, TObject::kOverwrite);
    tree->ResetBranchAddresses();
    
  } // end loop over vpt list

  return;
}


//_____________________________________________________________________________
//
// Get Corrections to the anode response
//
void vpt_analysis::get_anode_corrections(){
  
  cout << "  Calculating Anode Corrections..." << endl;

  bool verbose = false;

  // Loop over raw data files and fill root file
  for(std::vector<vptInfo*>::const_iterator tIter = vpt_list_.begin(); tIter != vpt_list_.end(); ++tIter){
    
    vptInfo *vpt = *tIter; // ptr to iterator

    if(verbose) cout << "    For VPT: " << vpt->tree_name_ << endl;
    
    bool hasOrangeData = (vpt->site_==site::uva && ( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) ) );

    TTree *tree = (TTree*)data_file_->Get(vpt->tree_name_.Data());

    tree->SetBranchStatus("*",               0);
    tree->SetBranchStatus("*_anode_*",       1);
    tree->SetBranchStatus("*pin_corr*",      1);
    if(vpt->site_==site::brunel){
      tree->SetBranchStatus("*vpt_div_pin*", 1);
    }

    TBranch *b_blue_ref=NULL,   *b_blue_ref_err=NULL;
    TBranch *b_blue_load=NULL,  *b_blue_load_err=NULL;
    TBranch *b_orange_ref=NULL, *b_orange_ref_err=NULL;
    

    measurement evt;
    initialize(evt);

    if(vpt->site_==site::brunel){

      tree->SetBranchStatus("blue_reference_pin",     1);
      tree->SetBranchStatus("blue_reference_pin_err", 1);

      // Create new branches
      b_blue_ref         = tree->Branch( "blue_reference_anode",          &evt.blue_reference_anode_,          "blue_reference_anode/F");
      b_blue_ref_err     = tree->Branch( "blue_reference_anode_err",      &evt.blue_reference_anode_err_,      "blue_reference_anode_err/F");
      
      TString vars = "";
      vars += "blue_reference_vpt_div_pin_NIM_corrected";
      vars += ":";
      vars += "blue_reference_anode_raw";
      vars += ":";
      vars += "blue_reference_anode_raw_err";
      vars += ":";
      vars += "blue_reference_pin";
      vars += ":";
      vars += "blue_reference_pin_err";
      //vars += "blue_reference_pin_correction";
      //vars += ":";
      //vars += "blue_reference_pin_correction_err";
      
      tree->Draw(vars, "", "para goff");

      Double_t *vpt_div_pin        = tree->GetVal(0);
      Double_t *anode              = tree->GetVal(1);
      Double_t *anode_err          = tree->GetVal(2);
      Double_t *pin                = tree->GetVal(3);
      Double_t *pin_err            = tree->GetVal(4);
      //Double_t *pin_correction     = tree->GetVal(3);
      //Double_t *pin_correction_err = tree->GetVal(4);

      int nEntries = tree->GetEntries();
      for(int i=0; i<nEntries; i++){
	
	initialize(evt);

	//evt.blue_reference_anode_      = anode[i]*pin_correction[i];
	evt.blue_reference_anode_      = vpt_div_pin[i];

	evt.blue_reference_anode_err_  = pow(anode_err[i] / anode[i], 2);
	evt.blue_reference_anode_err_ += pow(pin_err[i]/pin[i], 2);
	//evt.blue_reference_anode_err_ += pow(pin_correction_err[i]/pin_correction[i], 2);
	evt.blue_reference_anode_err_  = sqrt(evt.blue_reference_anode_err_);
	evt.blue_reference_anode_err_ *= evt.blue_reference_anode_;

	b_blue_ref->Fill();
	b_blue_ref_err->Fill();

      } // end loop over entries

    } // end if site is Brunel

    if(vpt->site_==site::uva){
      
      b_blue_ref         = tree->Branch( "blue_reference_anode",       &evt.blue_reference_anode_,          "blue_reference_anode/F");
      b_blue_ref_err     = tree->Branch( "blue_reference_anode_err",   &evt.blue_reference_anode_err_,      "blue_reference_anode_err/F");
      b_blue_load        = tree->Branch( "blue_load_anode",            &evt.blue_load_anode_,               "blue_load_anode/F");
      b_blue_load_err    = tree->Branch( "blue_load_anode_err",        &evt.blue_load_anode_err_,           "blue_load_anode_err/F");
      if(hasOrangeData){
	b_orange_ref     = tree->Branch( "orange_reference_anode",     &evt.orange_reference_anode_,        "orange_reference_anode/F");
	b_orange_ref_err = tree->Branch( "orange_reference_anode_err", &evt.orange_reference_anode_err_,    "orange_reference_anode_err/F");
      }


      // Vector to hold different PIN types
      vector<TString> led_branch;
      led_branch.push_back("blue_reference");
      if(vpt->site_==site::uva){
	led_branch.push_back("blue_load");
	if(hasOrangeData) led_branch.push_back("orange_reference");
      }
      
      
      // Loop over led_branch vector to form TString for anode corrections
      for(int iLed=0; iLed<(int)led_branch.size(); iLed++){

	TString vars = "";
	vars += led_branch[iLed] + "_anode_raw";
	vars += ":";
	vars += led_branch[iLed] + "_anode_raw_err";
	vars += ":";
	vars += led_branch[iLed] + "_pin_correction";
	vars += ":";
	vars += led_branch[iLed] + "_pin_correction_err";
      
	tree->Draw(vars, "", "para goff");

	Double_t *anode_raw          = tree->GetVal(0);     
	Double_t *anode_raw_err      = tree->GetVal(1);      
	Double_t *pin_correction     = tree->GetVal(2);
	Double_t *pin_correction_err = tree->GetVal(3);
	
	
	//
	// Calculate Anode PIN Corrections
	//
	int nEntries = tree->GetEntries();
	for(int i=0; i<nEntries; i++){
	
	  initialize(evt);
	
	  // PIN correction
	  double pinCorrectionX2   = (pin_correction[i] - 1)*2  + 1 ;
	  
	  // For error compare propagated error, to error based on no correction to x2 correction
	  double diff_noCorrection = fabs(anode_raw[i] - anode_raw[i]*pin_correction[i]);
	  double diff_x2Correction = fabs(anode_raw[i] - anode_raw[i]*pinCorrectionX2);
	
	  double anode_err_temp    = pow(anode_raw_err[i] / anode_raw[i], 2);
	  anode_err_temp          += pow(pin_correction_err[i] / pin_correction[i], 2);
	  anode_err_temp           = sqrt(anode_err_temp);
	  anode_err_temp          *= anode_raw[i]*pin_correction[i];
	
	  double anode_err_temp_v2 = 0.0;
	  anode_err_temp_v2 = std::max( anode_err_temp_v2, diff_noCorrection );
	  anode_err_temp_v2 = std::max( anode_err_temp_v2, diff_x2Correction );
	  anode_err_temp_v2 = std::max( anode_err_temp_v2, anode_err_temp );
	
	  
	  if(led_branch[iLed]=="blue_reference"){
	    evt.blue_reference_anode_     = anode_raw[i]*pin_correction[i];
	    evt.blue_reference_anode_err_ = anode_err_temp;
	    //evt.blue_reference_anode_err_ = anode_err_temp_v2;
	    b_blue_ref->Fill();
	    b_blue_ref_err->Fill();
	  }
	  
	  if(led_branch[iLed]=="blue_load"){
	    evt.blue_load_anode_     = anode_raw[i]*pin_correction[i];
	    evt.blue_load_anode_err_ = anode_err_temp;
	    //evt.blue_load_anode_err_ = anode_err_temp_v2;
	    b_blue_load->Fill();
	    b_blue_load_err->Fill();
	  }
	  
	  if(led_branch[iLed]=="orange_reference"){
	    evt.orange_reference_anode_     = anode_raw[i]*pin_correction[i];
	    evt.orange_reference_anode_err_ = anode_err_temp;
	    evt.orange_reference_anode_err_ = anode_err_temp_v2;
	    b_orange_ref->Fill();
	    b_orange_ref_err->Fill();
	  }
	  
	
	} // end loop over entries
      
      } // end loop over LED types

    } // end if site is UVa
    
    tree->SetBranchStatus("*", 1);
    tree->Write(vpt->tree_name_, TObject::kOverwrite);
    tree->ResetBranchAddresses();
    
  } // end loop over vpt list
  
  return;
}


//_____________________________________________________________________________
//
// add filter discrimantors to ttree
//
void vpt_analysis::get_filter_results(){

  cout << "  Calculating Filter Results..." << endl;

  bool verbose = false;

  //
  // Filters 
  //  1) Spike Filter
  //     a) blue/orange reference pin
  //
   
  // Loop over vpts and fill root file
  for(std::vector<vptInfo*>::const_iterator tIter = vpt_list_.begin(); tIter != vpt_list_.end(); ++tIter){
    
    vptInfo *vpt = *tIter; // ptr to iterator

    if(verbose) cout << "    For VPT: " << vpt->tree_name_ << endl;

    TTree *tree = (TTree*)data_file_->Get(vpt->tree_name_.Data());
      
    //
    // Brunel Filter
    //
    if(vpt->site_==site::brunel){

      continue;

    }
     
    //
    // UVa Filter
    //
    if(vpt->site_==site::uva){

      bool hasOrangeData = ( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) );
      
      tree->SetBranchStatus("*",                          0);
      tree->SetBranchStatus("blue_reference_pin",         1);
      tree->SetBranchStatus("blue_reference_pin_err",     1);
      if(hasOrangeData){
	tree->SetBranchStatus("orange_reference_pin",     1);
	tree->SetBranchStatus("orange_reference_pin_err", 1);
      }
      
      measurement evt;
      initialize(evt);
      
      TBranch *b_blue_ref_filter  = tree->Branch("blue_reference_spike_filter", &evt.blue_reference_spike_filter_, "blue_reference_spike_filter/I");
      TBranch *b_orng_ref_filter  = NULL;
      if(hasOrangeData){
	b_orng_ref_filter = tree->Branch("orange_reference_spike_filter", &evt.orange_reference_spike_filter_, "orange_reference_spike_filter/I");
      }
      
      // Vector to hold different PIN types
      vector<TString> led_branch;
      led_branch.push_back("blue_reference_pin");
      if(hasOrangeData) led_branch.push_back("orange_reference_pin");
            
      
      // Loop over led_branch vector to form TString for anode corrections
      for(int iLed=0; iLed<(int)led_branch.size(); iLed++){
	
	//
	// Get Variables for filtering
	//
	/*
	TString vars="";
	for(int iFriend=0; iFriend<(int)vpt->friend_trees_.size(); iFriend++){
	  if(iFriend==0) vars += "( (";
	  else           vars += " + ";

	  vars += vpt->friend_trees_[iFriend];
	  vars += ".";
	  vars += led_branch[iLed];
	
	} // end loop over friend trees

	vars += ")/";
	vars += (int)vpt->friend_trees_.size();
	vars += ".0 )";
       
	if((int)vpt->friend_trees_.size()==0) vars = led_branch[iLed];
	*/
	TString vars = led_branch[iLed];
	
	if(verbose) cout << "      Var String For " << led_branch[iLed] << " Filter = " << vars << endl;

	tree->Draw(vars, "", "para goff");
	int nEntries = tree->GetSelectedRows();

	Double_t *pin = tree->GetVal(0);
	
	// Declare arrays to hold averages
	Double_t avgBack=0.0, avgForw=0.0, sumBack=0.0, sumForw=0.0;
	Double_t sdBack=0.0, sdForw=0.0, sum2Back=0.0, sum2Forw=0.0; 
	deque<Double_t> list_back, list_forw, list_avg_forw;
	deque<Double_t> list_backSq, list_forwSq, list_sd_forw;

	// Values for averaging
	int numBack = 50;
	int numForw = 50;
		
	// loop over entries to compute forward errors
	for(int i=nEntries-1, count=0; i>=0; i--, count++){
	  
	  if(pin[i]<0) continue;

	  if(count < numForw){
	    avgForw  = pin[i];
	    sumForw += pin[i];
	  
	    list_forw.push_front(pin[i]);
	    list_avg_forw.push_front(pin[i]);
	    
	    sdForw    = pow( pin[i], 2 );
	    sum2Forw += pow( pin[i], 2 );
	    
	    list_sd_forw.push_front( sdForw );
	    list_forwSq.push_front( sdForw );
	  }
	  else{
	    avgForw = sumForw/numForw;
	    list_avg_forw.push_front(avgForw);

	    sumForw += pin[i];
	    sumForw -= *(list_forw.end());
	    list_forw.pop_back();
	    list_forw.push_front(pin[i]);

	    sdForw   = sum2Forw/numForw;
	    sdForw  -= pow( avgForw, 2 ); if(sdForw<0) cout << "NEGATIVE SDFORW! sum2Forw/numForw = " << sdForw << ", pow(avgForw,2) = " << pow(avgForw, 2) << endl;
	    sdForw   = sqrt(sdForw);
	    list_sd_forw.push_front( sdForw );

	    sum2Forw += pow( pin[i], 2 );
	    sum2Forw -= *(list_forwSq.end());
	    list_forwSq.pop_back();
	    list_forwSq.push_front( pow(pin[i], 2) );
	  }
	}

	int nVeto=0;
	for(int i=0; i<nEntries; i++){
	  
	  initialize(evt);
	  
	  // Booleans for spike filter
	  bool noSpikes = true; 

	  // Also check that pin is on
          if(pin[i]<0){
	    if(led_branch[iLed]=="blue_reference"){
	      evt.blue_reference_spike_filter_ = (noSpikes) ? 1 : 0;
	      if(!evt.blue_reference_spike_filter_) nVeto++;
	      b_blue_ref_filter->Fill();
	    }	
	    if(led_branch[iLed]=="orange_reference"){
	      evt.orange_reference_spike_filter_ = (noSpikes) ? 1 : 0;
	      if(!evt.blue_reference_spike_filter_) nVeto++;
	      b_orng_ref_filter->Fill();
	    }
	    continue;
	  }
	    
	  	  
	  // if too early in dataset to form backwards avg
	  if(i < numBack){
	    
	    avgBack  = pin[i];
	    sumBack += pin[i];
	    list_back.push_back(pin[i]);
	    
	    sum2Back += pow( pin[i], 2 );
	    list_backSq.push_back( pow( pin[i], 2 ) );

	    noSpikes = true;
	  }
	
	  // if too late in the data set to form forwards avg
	  else if(i+numForw>=nEntries) noSpikes = true;

	  // perform spike filter
	  else{
	    
	    avgBack = sumBack/numBack;
	    
	    // Compare Current Event To Avg & Std Dev
	    int thresh = 2;

	    sdBack  = sum2Back/numBack;
	    sdBack -= pow( avgBack, 2 );
	    sdBack  = sqrt(sdBack);

	    noSpikes = ( ( fabs(pin[i] - avgBack)          < thresh*sdBack)         || 
			 ( fabs(pin[i] - list_avg_forw[i]) < thresh*list_sd_forw[i])   );
	    
	    if(verbose && i%10000==0){
	      cout << "      Good Point? = " << noSpikes << endl;
	      cout << "          AvgForw = " << list_avg_forw[i] << " +/- " << list_sd_forw[i] << endl;
	      cout << "          AvgBack = " << avgBack << " +/- " << sdBack << endl;
	      cout << "          Pin[i]  = " << pin[i] << endl;
	      cout << endl;
	    }

	    if(noSpikes){

	      // Update backwards averages by adding this new point
	      sumBack += pin[i];
	      sumBack -= list_back[0];
	      list_back.push_back(pin[i]);
	      list_back.pop_front();
	      
	      sum2Back += pow( pin[i], 2 );
	      sum2Back -= list_backSq[0];
	      list_backSq.push_back( pow( pin[i], 2 ) );
	      list_backSq.pop_front();
	    }
	    else{
	      if(verbose && nVeto%100==0){
		cout << "        Spike Found! " << led_branch[iLed] << endl;
		cout << "          AvgForw = " << list_avg_forw[i] << " +/- " << list_sd_forw[i] << endl;
		cout << "          AvgBack = " << avgBack << " +/- " << sdBack << endl;
		cout << "          Pin[i]  = " << pin[i] << endl;
	      }
	    }
	      
      
	  } // end spike filter
      

	  //
	  // Fill branches
	  //
	  if(led_branch[iLed]=="blue_reference_pin"){
	    evt.blue_reference_spike_filter_ = (noSpikes) ? 1 : 0;
	    if(!evt.blue_reference_spike_filter_) nVeto++;
	    b_blue_ref_filter->Fill();
	  }	
	  if(led_branch[iLed]=="orange_reference_pin"){
	    evt.orange_reference_spike_filter_ = (noSpikes) ? 1 : 0;
	    if(!evt.blue_reference_spike_filter_) nVeto++;
	    b_orng_ref_filter->Fill();
	  }
	  
	  
	} // end loop over entries
	

	// Debug statement
	if(true){
	  cout << "      For LED: " << led_branch[iLed] << endl;
	  cout << "        N entries read in = " << nEntries;
	  cout << ", N entries vetoed = " << nVeto;
	  cout << ", pass efficiency = " << (double)(nEntries-nVeto)/(double)nEntries;
	  cout << endl << endl;
	}

      } // end loop over leds
      
    } // end if site is U.Va



    tree->SetBranchStatus("*", 1);
    tree->Write(vpt->tree_name_, TObject::kOverwrite);
    tree->ResetBranchAddresses();
    
  } // end loop over vpt list
  
  return;
}


//_____________________________________________________________________________
//
// Draw Plots
//
void vpt_analysis::get_plots(vector<plotInfo> &plotList){
  
  bool verbose = false;

  // 
  // Global Style Variables
  //
  gStyle->SetTitleAlign(23);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFillColor(0);

  
  // Vectors to hold fit results for overlays
  v_vpt_plot brunel_run1_fit_blue;
  v_vpt_plot brunel_run2_fit_blue;
  v_vpt_plot uva_run1_fit_blue;
  v_vpt_plot uva_run2_fit_blue;
  v_vpt_plot uva_run3_fit_blue;
  v_vpt_plot uva_run4_fit_blue;
  v_vpt_plot uva_run5_fit_blue;
  v_vpt_plot uva_run6_fit_blue;
  v_vpt_plot uva_good_runs_fit_blue;
  v_vpt_plot uva_all_runs_fit_blue;
  
  v_vpt_plot brunel_run1_fit_orng;
  v_vpt_plot brunel_run2_fit_orng;
  v_vpt_plot uva_run1_fit_orng;
  v_vpt_plot uva_run2_fit_orng;
  v_vpt_plot uva_run3_fit_orng;
  v_vpt_plot uva_run4_fit_orng;
  v_vpt_plot uva_run5_fit_orng;
  v_vpt_plot uva_run6_fit_orng;
  v_vpt_plot uva_good_runs_fit_orng;
  v_vpt_plot uva_all_runs_fit_orng;


  // Loop over plot list 
  for(vector<plotInfo>::const_iterator tIter1 = plotList.begin(); tIter1 != plotList.end(); ++tIter1) {
    
    const plotInfo plot = *tIter1;
    
    vpt_plot this_pair;
    v_vpt_plot brunel_run1;
    v_vpt_plot brunel_run2;
    v_vpt_plot uva_run1;
    v_vpt_plot uva_run2;
    v_vpt_plot uva_run3;
    v_vpt_plot uva_run4;
    v_vpt_plot uva_run5;
    v_vpt_plot uva_run6;
    v_vpt_plot uva_good_runs;
    v_vpt_plot uva_all_runs;
    
    // TStrings for variables to plot
    bool has_yErr = (plot.yBranch_err!="");
    bool has_xErr = (plot.xBranch_err!="");
     
    // Loop over list of vpts
    vector<TGraphErrors*> graphList;
    for(vector<vptInfo*>::const_iterator tIter2 = vpt_list_.begin(); tIter2 != vpt_list_.end(); ++tIter2){
      
      vptInfo *vpt = *tIter2;
      
      TTree *tree = (TTree*)data_file_->Get(vpt->tree_name_);      
      
      if( (plot.whichVpt!="") && (plot.whichVpt != vpt->tree_name_) ) continue;

      //
      // Test to see if this tree has all the variables necessary
      //
      bool hasVars = true;
      
      TTreeFormula *testY = new TTreeFormula("testY", plot.yBranch, tree);
      hasVars = (testY->GetNdim()>0) && (testY->GetNdata()>0);
      if(!hasVars) continue;

      TTreeFormula *testX = new TTreeFormula("testX", plot.xBranch, tree);
      hasVars = (testX->GetNdim()>0) && (testX->GetNdata()>0);
      if(!hasVars) continue;

      TTreeFormula *testYerr=NULL;
      if(has_yErr){
	testYerr = new TTreeFormula("testYerr", plot.yBranch_err, tree);
	hasVars = (testYerr->GetNdim()>0) && (testYerr->GetNdata()>0);
	if(!hasVars) continue;
      }
      TTreeFormula *testXerr=NULL;
      if(has_xErr){
	testXerr= new TTreeFormula("testXerr", plot.xBranch_err, tree);
	hasVars = (testXerr->GetNdim()>0) && (testXerr->GetNdata()>0);
	if(!hasVars) continue;
      }
      
      /*
      // Set-up title
      TString plot_title = "CMS Preliminary, ";
      if(vpt->site_==site::brunel) plot_title += "Brunel site, ";
      if(vpt->site_==site::uva)    plot_title += "U.Va. site, ";

      if(vpt->run_num_==run_num::run1) plot_title += "Run 1, ";
      if(vpt->run_num_==run_num::run2) plot_title += "Run 2, ";
      if(vpt->run_num_==run_num::run3) plot_title += "Run 3, ";
      if(vpt->run_num_==run_num::run4) plot_title += "Run 4, ";
      if(vpt->run_num_==run_num::run5) plot_title += "Run 5, ";
      if(vpt->run_num_==run_num::run6) plot_title += "Run 6, ";

      plot_title += "vpt" + vpt->rie_number_;
      plot_title += ", ";
      plot_title += plot.title;

      TString extra_title = "";
      if(plot.applyAveraging) {
	extra_title += ", Averaged over ";
	extra_title += plot.numToAvg*2;
	extra_title += " points";
      }
      if(plot.applyNormalize) extra_title += ", Normalized to Start of Run"; 
      
      plot_title += extra_title;
      */
      if(verbose) cout << "   Drawing Plot: " << plot.yBranch << " vs " << plot.xBranch << endl;

      // Create Canvas 
      TCanvas *can = new TCanvas("can", "can" , 10, 10, 1000, 600);
      can->SetGrid();
        
      // TStrings for filters
      TString cuts="(  "; 
      if(plot.extraCuts!="") cuts += "( " + plot.extraCuts + " )";
              
      //
      // Remove -99.9, -1 flags from plot variable - always done
      //
      if(cuts!="(  ") cuts+=" && ";
      cuts+="( "; 
      cuts+=plot.yBranch;       cuts+=">-1"; 
      if(plot.yBranch_err!=""){
	cuts += " && ";
	cuts+=plot.yBranch_err; cuts+=" >-1"; 
      }
      cuts+=" && ";
      cuts+=plot.xBranch;       cuts+=">-1";
      if(plot.xBranch_err!=""){
	cuts+=" && ";
	cuts+=plot.xBranch_err; cuts+=">-1 ";
      }
      cuts+=" )";


      //
      // Only Plot from vpt->run_begin_
      //
      cuts += " && (elapsed_time>";
      cuts += vpt->run_begin_;
      cuts += ")";

      //
      // Apply is_good_event_ flag
      //
      //cuts+=" && (relative_err_filter==1)";
      //if(vpt->site_==site::uva){
      //cuts+=" && (blue_reference_spike_filter==1)";
      //  if( !(vpt->run_num_==run_num::run1) && !(vpt->run_num_==run_num::run2) ){
      //    cuts+=" && (orange_reference_spike_filter==1)";
      //  }
      //}
      

      // End parantheses for cut
      cuts+="  )";
    
      TString vars=""; 
      vars+= plot.yBranch; 
      vars+= ":"; 
      vars+= plot.xBranch; 
      if(has_yErr){
	vars+= ":";
	vars+=plot.yBranch_err;
      }
      if(has_xErr){
	vars+= ":";
	vars+=plot.xBranch_err;
      }
      
      TH2F *h2=NULL;
      TH3F *h3=NULL;
      
      bool is2d = (plot.yBranch_err=="" && plot.xBranch_err=="");
      TString thisHist = (is2d) ? " >> h2" : " >> h3";
	

      //
      // Draw Plot
      //
      if(verbose){
	cout << "vars = " << vars << endl;
	cout << "cuts = " << cuts << endl;
	cout << endl;
      }
      tree->Draw(vars + thisHist, cuts, "goff");
      int nEntries = tree->GetSelectedRows();


      //
      // Check for failed drawing attempts
      //
      if(nEntries==0){
	cout << "  ZERO ENTRIES DRAWN FOR: " << vars << ", with cuts " << cuts << endl;

	if(is2d){
	  h2 = (TH2F*)gDirectory->Get("h2");
	  h2->~TH2F();
	}
	else{
	  h3 = (TH3F*)gDirectory->Get("h3");
	  h3->~TH3F();
	}
	can->~TCanvas();
	
	continue;
      }

      TGraphErrors *gr1=NULL;
      if( !has_yErr && !has_xErr )     gr1 = new TGraphErrors(nEntries,tree->GetV2(),tree->GetV1(),NULL,         NULL);    
      else if( has_yErr && !has_xErr ) gr1 = new TGraphErrors(nEntries,tree->GetV2(),tree->GetV1(),NULL,         tree->GetV3());
      else if( !has_yErr && has_xErr ) gr1 = new TGraphErrors(nEntries,tree->GetV2(),tree->GetV1(),tree->GetV3(),NULL);
      else                             gr1 = new TGraphErrors(nEntries,tree->GetV2(),tree->GetV1(),tree->GetV4(),tree->GetV3());
      
      if(is2d) h2 = (TH2F*)gDirectory->Get("h2");
      else     h3 = (TH3F*)gDirectory->Get("h3");

      
      //
      // If Averaging, then compute rolling average
      //
      if(plot.applyAveraging){
	
        deque<Float_t> valsInAvg, valsInAvgErrY, valsInAvgErrX; 
        double avg=0, sum=0, avg_errY=0, sum_errY=0, avg_errX=0, sum_errX=0;

        Double_t *xVals = tree->GetV2();  
        Double_t *yVals = tree->GetV1();  
	Double_t *xVals_err=NULL, *yVals_err=NULL;
	if( has_yErr && !has_xErr ) yVals_err = tree->GetV3();
	if( !has_yErr && has_xErr ) xVals_err = tree->GetV3();
	if( has_yErr && has_xErr ){
	  xVals_err = tree->GetV4();
	  yVals_err = tree->GetV3();
	}

	gr1->Set(0); // Reset TGraphErrors

        for(int i=0; i<nEntries; i++){
          if(i < plot.numToAvg){

            gr1->SetPoint(i, xVals[i], yVals[i]);
	    if( has_yErr && !has_xErr ) gr1->SetPointError(i, 0, yVals_err[i]);
	    if( !has_yErr && has_xErr ) gr1->SetPointError(i, xVals_err[i], 0);
	    if( has_yErr && has_xErr  ) gr1->SetPointError(i, xVals_err[i], yVals_err[i]);

            sum += yVals[i];
            valsInAvg.push_back(yVals[i]); 
	    
	    if(has_yErr){
	      sum_errY += pow( yVals_err[i], 2);
	      valsInAvgErrY.push_back( pow( yVals_err[i], 2) );
	    }
	    if(has_xErr){
	      sum_errX += pow( xVals_err[i], 2);
	      valsInAvgErrX.push_back( pow( xVals_err[i], 2) );
	    }
	    
	  }
	  else if(i+plot.numToAvg>=nEntries) break;
	  // Perform Averaging
          else{
	    
	    double sum_forw=0.0;
	    for(int j=i; j<i+1+plot.numToAvg; j++) sum_forw += yVals[j];
	    avg  = (sum+sum_forw)/(2.0*plot.numToAvg+1);
	    sum += yVals[i];
	    sum -= valsInAvg[0];
	    valsInAvg.pop_front();
	    valsInAvg.push_back(yVals[i]);

	    gr1->SetPoint(i, xVals[i], avg);     

	    if(has_yErr){
	      double sum_errY_forw=0.0;
	      for(int j=i; j<i+1+plot.numToAvg; j++) sum_errY_forw += pow(yVals_err[j],2);
	      avg_errY  = sqrt(sum_errY+sum_errY_forw)/(2.0*plot.numToAvg+1);
	      sum_errY += pow(yVals_err[i],2);
	      sum_errY -= valsInAvgErrY[0];
	      valsInAvgErrY.pop_front();
	      valsInAvgErrY.push_back( pow(yVals_err[i],2) );
	    }

	    if(has_xErr){	      
	      double sum_errX_forw=0.0;
	      for(int j=i; j<i+1+plot.numToAvg; j++) sum_errX_forw += pow(xVals_err[j],2);
	      avg_errX  = sqrt(sum_errX+sum_errX_forw)/(2.0*plot.numToAvg+1);
	      sum_errX += pow(xVals_err[i],2);
	      sum_errX -= valsInAvgErrX[0];
	      valsInAvgErrX.pop_front();
	      valsInAvgErrX.push_back( pow(xVals_err[i],2) );
	    }
	    
	    if( has_yErr && !has_xErr ) gr1->SetPointError(i, 0, avg_errY);
	    if( !has_yErr && has_xErr ) gr1->SetPointError(i, avg_errX, 0);
	    if( has_yErr && has_xErr  ) gr1->SetPointError(i, avg_errX, avg_errY);

	  } // end calculating average and error for this point
        } // end loop over entries
      } // end if averaging 

      
      
      //
      // Fit Data
      //
      TF1 *fit=NULL;
      TLegend *leg=NULL;
      if(plot.applyFit){

        fit = new TF1("fit", plot.formula.Data()); 
        fit->SetLineColor(kRed);

        for(int i=0; i<(int)plot.paramNames_param.size();  i++) fit->SetParName  (plot.paramNames_param[i],  plot.paramNames_name[i]);
        for(int i=0; i<(int)plot.constraints_param.size(); i++) fit->SetParLimits(plot.constraints_param[i], plot.constraints_low[i], plot.constraints_high[i]);
        for(int i=0; i<(int)plot.initialVals_param.size(); i++) fit->SetParameter(plot.initialVals_param[i], plot.initialVals_val[i]);

	if(plot.rangeLow!=-1 && plot.rangeHigh!=-1){
	  fit->SetRange(plot.rangeLow, plot.rangeHigh);
	}
	else {
	  fit->SetRange(gr1->GetX()[0], gr1->GetX()[gr1->GetN()-1]);
	}
        gr1->Fit("fit", "r+");

	
	//
	// Get Fit Results
	//
	if(plot.formulaName=="Double Exponential"){
	  
	  if( plot.yBranch.Contains("blue_reference_anode") ){
	    v_blue_ref_fit_c_.push_back(fit->GetParameter(0));
	    if(fit->GetParameter(2)>fit->GetParameter(4)){ // > since vals are -
	      v_blue_ref_fit_a1_.push_back(fit->GetParameter(1));
	      v_blue_ref_fit_t1_.push_back(fit->GetParameter(2));
	      v_blue_ref_fit_a2_.push_back(fit->GetParameter(3));
	      v_blue_ref_fit_t2_.push_back(fit->GetParameter(4));
	    }
	    else{
	      v_blue_ref_fit_a1_.push_back(fit->GetParameter(3));
	      v_blue_ref_fit_t1_.push_back(fit->GetParameter(4));
	      v_blue_ref_fit_a2_.push_back(fit->GetParameter(1));
	      v_blue_ref_fit_t2_.push_back(fit->GetParameter(2));
	    }
	    v_blue_ref_fit_all_t_.push_back(fit->GetParameter(2));
	    v_blue_ref_fit_all_t_.push_back(fit->GetParameter(4));
	    v_blue_ref_fit_chi2_.push_back(fit->GetChisquare()/fit->GetNDF());
	    v_blue_ref_fit_drop_.push_back( 100*fabs(fit->Eval(0) - fit->Eval(0.02))/fit->Eval(0) );
	    v_blue_ref_fit_rieNum_.push_back( vpt->rie_number_ );

	    vpt->fit_blue_ = fit;
	  }
	  if( plot.yBranch.Contains("orange_reference_anode") ){
	    v_orng_ref_fit_c_.push_back(fit->GetParameter(0));
	    if(fit->GetParameter(2)>fit->GetParameter(4)){ // > since vals are -
	      v_orng_ref_fit_a1_.push_back(fit->GetParameter(1));
	      v_orng_ref_fit_t1_.push_back(fit->GetParameter(2));
	      v_orng_ref_fit_a2_.push_back(fit->GetParameter(3));
	      v_orng_ref_fit_t2_.push_back(fit->GetParameter(4));
	    }
	    else{
	      v_orng_ref_fit_a1_.push_back(fit->GetParameter(3));
	      v_orng_ref_fit_t1_.push_back(fit->GetParameter(4));
	      v_orng_ref_fit_a2_.push_back(fit->GetParameter(1));
	      v_orng_ref_fit_t2_.push_back(fit->GetParameter(2));
	    }
	    v_orng_ref_fit_all_t_.push_back(fit->GetParameter(2));
	    v_orng_ref_fit_all_t_.push_back(fit->GetParameter(4));
	    v_orng_ref_fit_chi2_.push_back(fit->GetChisquare()/fit->GetNDF()); 
	    v_orng_ref_fit_drop_.push_back( 100*fabs(fit->Eval(0) - fit->Eval(0.02))/fit->Eval(0) );
	    v_orng_ref_fit_rieNum_.push_back( vpt->rie_number_ );

	    vpt->fit_orng_ = fit;
	  }
	}
	

	//
	// Add Legend
	//
	leg = new TLegend(0.60, 0.80, 0.90, 0.90);
	leg->SetTextSize(0.030);
	leg->SetFillStyle(1001);
	leg->SetFillColor(0);

	leg->AddEntry(gr1, "vpt"+vpt->rie_number_,"lp");

        TString funcName = "f(x) = "; 
	if((int)plot.paramNames_param.size()>0){
	  TString formula_temp = plot.formula;
	  for(int i=0; i<(int)plot.paramNames_param.size(); i++){
	    TString replace_this = "["; 
	    replace_this        += plot.paramNames_param[i];
	    replace_this        += "]";
	    TString with_this    = plot.paramNames_name[i];
	    formula_temp.ReplaceAll(replace_this.Data(), with_this.Data());
	  }
	  funcName += formula_temp;
	}
	else  funcName+=plot.formula;

	if(plot.formulaName=="Double Exponential"){
	  funcName = "f(x) = C + \\Alpha_{1}\\upointe^{x/\\tau_{1}} + \\Alpha_{2}\\upointe^{x/\\tau_{2}}";
	}

        leg->AddEntry(fit, "#font[12]{"+funcName+"}", "mlp");
        
	
	
      }

      
      //
      // If Normalizing, then do it!
      //
      TF1 *fit_norm=NULL;
      double norm = gr1->GetY()[0];
      if(plot.applyNormalize && gr1){
	
	Double_t *yVals     = gr1->GetY();
	Double_t *yVals_err = gr1->GetEY();
	Double_t *xVals     = gr1->GetX();
	Double_t *xVals_err = gr1->GetEX();
	
	for(int i=0; i<(int)gr1->GetN(); i++){
	  gr1->SetPoint(i, xVals[i], yVals[i]/norm);

	  if( has_yErr && !has_xErr ) gr1->SetPointError(i, 0, yVals_err[i]/norm);
	  if( !has_yErr && has_xErr ) gr1->SetPointError(i, xVals_err[i], 0);
	  if( has_yErr && has_xErr  ) gr1->SetPointError(i, xVals_err[i], yVals_err[i]/norm);
	}

	if(plot.applyFit){
	  TString fit_norm_function = "(" + fit->GetExpFormula("p");
	  fit_norm_function += ")/";
	  fit_norm_function += norm;
	  fit_norm = new TF1("fit_norm", fit_norm_function.Data());
	  if(plot.rangeLow!=-1 && plot.rangeHigh!=-1){
	    fit_norm->SetRange(plot.rangeLow, plot.rangeHigh);
	  }
	  else {
	    fit_norm->SetRange(gr1->GetX()[0], gr1->GetX()[gr1->GetN()-1]);
	  }
	  fit_norm->SetLineColor(kRed);
	}

	if( plot.yBranch.Contains("orange_reference_anode") ) vpt->fit_orng_norm_ = fit_norm;
	if( plot.yBranch.Contains("blue_reference_anode") )   vpt->fit_blue_norm_ = fit_norm;

      } // end if normalizing

      
      //
      // Plot attributes
      //
      gr1->SetTitle(0);
      TLatex title;
      title.SetNDC();
      title.SetTextAlign(21);
      title.SetTextFont(42);
      title.SetTextSize(0.032);
      
      gr1->GetXaxis()->SetTitle(plot.xAxisTitle);
      gr1->GetYaxis()->SetTitle(plot.yAxisTitle);

      gr1->SetLineColor(vpt->color_);
      gr1->SetFillColor(vpt->color_);
      gr1->SetMarkerColor(vpt->color_);      
      //gr1->SetMarkerStyle(20);
      //gr1->SetMarkerSize(0.25);
      
      
      // Axis Range, adjust if extending fit beyond data
      double plotMin = gr1->GetXaxis()->GetXmin();
      double plotMax = gr1->GetXaxis()->GetXmax();
      double fitMin = plotMin;
      double fitMax = plotMax;
      if(plot.applyFit) fitMin = plot.rangeLow;
      if(plot.applyFit) fitMax = plot.rangeHigh;
      if(fitMin<plotMin) plotMin = fitMin;
      if(fitMax>plotMax) plotMax = fitMax;
      gr1->GetXaxis()->SetLimits(plotMin, plotMax);


      //
      // Draw TGraphErrors
      //
      gr1->Draw("AP");   
      if(plot.applyFit){
	leg->Draw();
	if(plot.applyNormalize) fit_norm->Draw("same");
	else                    fit->Draw("same"); 
	// Get Fit Data
	gStyle->SetOptFit(1);
        gPad->Update();
	TPaveStats *stats = (TPaveStats*)gr1->FindObject("stats");
        stats->SetX1NDC(0.60);
	stats->SetX2NDC(0.90);
	stats->SetY1NDC(0.50);
	stats->SetY2NDC(0.80);
	stats->SetTextSize(.035);
	stats->SetFillStyle(1001);
      }
      can->Update(); 
      

      //
      //  Group Plots for Overlays
      //
      this_pair.first  = vpt;
      this_pair.second = gr1;

      if(gr1->GetN()>0){
	if(vpt->site_==site::brunel){
	  if(vpt->run_num_==run_num::run1){
	    brunel_run1.push_back(this_pair);
	    brunel_run1_fit_blue.push_back(this_pair);
	  }
	  if(vpt->run_num_==run_num::run2){
	    brunel_run2.push_back(this_pair);
	    brunel_run2_fit_blue.push_back(this_pair);
	  }
	}
	if(vpt->site_==site::uva){
	  if(vpt->run_num_==run_num::run1){ 
	    uva_run1.push_back(this_pair);
	    if( plot.yBranch.Contains("blue_reference_anode") ){   uva_run1_fit_blue.push_back(this_pair);}
	    if( plot.yBranch.Contains("orange_reference_anode") ){ uva_run1_fit_orng.push_back(this_pair);}
	      
	  }
	  if(vpt->run_num_==run_num::run2){ 
	    uva_run2.push_back(this_pair); 
	    uva_good_runs.push_back(this_pair);
	    if( plot.yBranch.Contains("blue_reference_anode") ){   uva_run2_fit_blue.push_back(this_pair); uva_good_runs_fit_blue.push_back(this_pair); }
	    if( plot.yBranch.Contains("orange_reference_anode") ){ uva_run2_fit_orng.push_back(this_pair); uva_good_runs_fit_orng.push_back(this_pair); }
	  }
	  if(vpt->run_num_==run_num::run3){ 
	    uva_run3.push_back(this_pair); 
	    uva_good_runs.push_back(this_pair);
	    if( plot.yBranch.Contains("blue_reference_anode") ){   uva_run3_fit_blue.push_back(this_pair); uva_good_runs_fit_blue.push_back(this_pair); }
	    if( plot.yBranch.Contains("orange_reference_anode") ){ uva_run3_fit_orng.push_back(this_pair); uva_good_runs_fit_orng.push_back(this_pair); }
	  }
	  if(vpt->run_num_==run_num::run4){
	    uva_run4.push_back(this_pair);
	    if( plot.yBranch.Contains("blue_reference_anode") ){   uva_run4_fit_blue.push_back(this_pair); }
	    if( plot.yBranch.Contains("orange_reference_anode") ){ uva_run4_fit_orng.push_back(this_pair); }
	  }
	  if(vpt->run_num_==run_num::run5){ 
	    uva_run5.push_back(this_pair); 
	    uva_good_runs.push_back(this_pair);
	    if( plot.yBranch.Contains("blue_reference_anode") ){   uva_run5_fit_blue.push_back(this_pair); uva_good_runs_fit_blue.push_back(this_pair); }
	    if( plot.yBranch.Contains("orange_reference_anode") ){ uva_run5_fit_orng.push_back(this_pair); uva_good_runs_fit_orng.push_back(this_pair); }
	  }
	  if(vpt->run_num_==run_num::run6){ 
	    uva_run6.push_back(this_pair); 
	    uva_good_runs.push_back(this_pair);
	    if( plot.yBranch.Contains("blue_reference_anode") ){   uva_run6_fit_blue.push_back(this_pair); uva_good_runs_fit_blue.push_back(this_pair); }
	    if( plot.yBranch.Contains("orange_reference_anode") ){ uva_run6_fit_orng.push_back(this_pair); uva_good_runs_fit_orng.push_back(this_pair); }
	  }

	  uva_all_runs.push_back(this_pair);
	  if( plot.yBranch.Contains("blue_reference_anode") ){   uva_all_runs_fit_blue.push_back(this_pair); }
	  if( plot.yBranch.Contains("orange_reference_anode") ){ uva_all_runs_fit_orng.push_back(this_pair); }
	  
	}
      }

      // Draw Title after all Canvas Updates
      title.DrawLatex(0.5, 0.95, plot.title);
      
      //
      // Create TString to save output
      //
      TString saveMe = "../plots/";
     
      if(vpt->site_==site::brunel) saveMe += "brunel_";
      if(vpt->site_==site::uva)    saveMe += "uva_";
 
      if(vpt->run_num_==run_num::run1) saveMe += "run1_";
      if(vpt->run_num_==run_num::run2) saveMe += "run2_";
      if(vpt->run_num_==run_num::run3) saveMe += "run3_";
      if(vpt->run_num_==run_num::run4) saveMe += "run4_";
      if(vpt->run_num_==run_num::run5) saveMe += "run5_";
      if(vpt->run_num_==run_num::run6) saveMe += "run6_";
      
      if(plot.applyFit) saveMe += "Fit_";

      saveMe += "vpt" + vpt->rie_number_;

      TString saveMeY = plot.yBranch;
      saveMeY.ReplaceAll("(", "");
      saveMeY.ReplaceAll(")", "");
      saveMeY.ReplaceAll("/", "_div_");
      saveMeY.ReplaceAll("\\*", "_times_");
      
      TString saveMeX = plot.xBranch;
      saveMeX.ReplaceAll("(", "");
      saveMeX.ReplaceAll(")", "");
      saveMeX.ReplaceAll("/", "_div_");
      saveMeX.ReplaceAll("\\*", "_times_");

      saveMe += "__" + saveMeY;
      saveMe += "__vs__";
      saveMe += saveMeX;
      if(plot.applyAveraging){
	saveMe += "__rolling_average_of_";
	saveMe += (int)2.0*plot.numToAvg;
	saveMe += "pts";
      }
      if(plot.applyNormalize) saveMe += "__normalized_to_start_of_run";
      if(plot.applyFit)       saveMe += "__fitted_with_" + plot.formulaName;
         
      saveMe.ReplaceAll(" ", "_");
      
      if(verbose) cout << "Saving Plot: " << saveMe << endl;

      //TString saveMeC   = saveMe + ".C";
      //can->SaveAs(saveMeC,   ""); 
      
      //TString saveMeGif = saveMe + ".gif";
      //can->SaveAs(saveMeGif, "");
      
      //TString saveMePdf = saveMe + ".pdf";
      //can->SaveAs(saveMePdf, "");

      TString saveMePng = saveMe + ".png";
      can->SaveAs(saveMePng, "");

      
      if(analysis_type_ == analysis_type::plot){
	plot_file_->WriteObject(can, saveMe);
      }
      if(analysis_type_ == analysis_type::fit){
	fit_file_->WriteObject(can, saveMe);
      }

      can->~TCanvas();
      if(is2d) h2->~TH2F();
      else     h3->~TH3F();

    } // end loop over vpt list
        
   
    //
    // Draw Overlay Plots
    //
    if(!plot.applyFit){
      get_overlay_plots(brunel_run1,   plot);
      get_overlay_plots(brunel_run2,   plot);
      get_overlay_plots(uva_run1,      plot);
      get_overlay_plots(uva_run2,      plot);
      get_overlay_plots(uva_run3,      plot);
      get_overlay_plots(uva_run4,      plot);
      get_overlay_plots(uva_run5,      plot);
      get_overlay_plots(uva_run6,      plot);
      get_overlay_plots(uva_good_runs, plot);
      get_overlay_plots(uva_all_runs,  plot);
    }

  } // end loop over plot list

  
  //
  // Draw Overlay Plots
  //
  plotInfo bluePlot, orngPlot;
  for(int iPlot=0; iPlot<(int)plotList.size(); iPlot++){
    if( plotList[iPlot].yBranch.Contains("blue_reference_anode") ){   bluePlot = plotList[iPlot]; break; }
  }
  for(int iPlot=0; iPlot<(int)plotList.size(); iPlot++){
    if( plotList[iPlot].yBranch.Contains("orange_reference_anode") ){ orngPlot = plotList[iPlot]; break; }
  }

  if(bluePlot.applyFit){
    get_overlay_plots(brunel_run1_fit_blue,   bluePlot);
    get_overlay_plots(brunel_run2_fit_blue,   bluePlot);
    get_overlay_plots(uva_run1_fit_blue,      bluePlot);
    get_overlay_plots(uva_run2_fit_blue,      bluePlot);
    get_overlay_plots(uva_run3_fit_blue,      bluePlot);
    get_overlay_plots(uva_run4_fit_blue,      bluePlot);
    get_overlay_plots(uva_run5_fit_blue,      bluePlot);
    get_overlay_plots(uva_run6_fit_blue,      bluePlot);
    get_overlay_plots(uva_good_runs_fit_blue, bluePlot, "all_good_runs");
    get_overlay_plots(uva_all_runs_fit_blue,  bluePlot, "all_runs");
  }
  if(orngPlot.applyFit){
    get_overlay_plots(uva_run1_fit_orng,      orngPlot);
    get_overlay_plots(uva_run2_fit_orng,      orngPlot);
    get_overlay_plots(uva_run3_fit_orng,      orngPlot);
    get_overlay_plots(uva_run4_fit_orng,      orngPlot);
    get_overlay_plots(uva_run5_fit_orng,      orngPlot);
    get_overlay_plots(uva_run6_fit_orng,      orngPlot);
    get_overlay_plots(uva_good_runs_fit_orng, orngPlot, "all_good_runs");
    get_overlay_plots(uva_all_runs_fit_orng,  orngPlot, "all_runs");
  }


  return;
}

    
//_____________________________________________________________________________
//
// Draw Overlay Plots
//
void vpt_analysis::get_overlay_plots(v_vpt_plot &plotList, plotInfo plot, TString groupDescription){
  
  bool verbose = false;

  if((int)plotList.size()==0) return;

  // 
  // Global Atributes
  //
  gROOT->ForceStyle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetTitleAlign(23);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFillColor(0);
  

  if((int)plotList.size()>5){
    for(int iPlot=0; iPlot<(int)plotList.size(); iPlot++){
      if(plotList[iPlot].first->rie_number_=="947")   plotList[iPlot].second->SetLineColor(kAzure+2);

      if(plotList[iPlot].first->rie_number_=="2181")  plotList[iPlot].second->SetLineColor(kYellow+1);
      if(plotList[iPlot].first->rie_number_=="2182")  plotList[iPlot].second->SetLineColor(kYellow+3);
      if(plotList[iPlot].first->rie_number_=="2183")  plotList[iPlot].second->SetLineColor(kYellow+4);
      if(plotList[iPlot].first->rie_number_=="2184")  plotList[iPlot].second->SetLineColor(kYellow-5);
      if(plotList[iPlot].first->rie_number_=="2185")  plotList[iPlot].second->SetLineColor(kYellow-7);

      if(plotList[iPlot].first->rie_number_=="7095")  plotList[iPlot].second->SetLineColor(kGreen+1);
      if(plotList[iPlot].first->rie_number_=="7099")  plotList[iPlot].second->SetLineColor(kGreen+3);
      if(plotList[iPlot].first->rie_number_=="7112")  plotList[iPlot].second->SetLineColor(kGreen+1);
      if(plotList[iPlot].first->rie_number_=="7120")  plotList[iPlot].second->SetLineColor(kGreen-5);
      if(plotList[iPlot].first->rie_number_=="7182")  plotList[iPlot].second->SetLineColor(kGreen-7);
      

      if(plotList[iPlot].first->rie_number_=="12199") plotList[iPlot].second->SetLineColor(kCyan+1);
      if(plotList[iPlot].first->rie_number_=="12797") plotList[iPlot].second->SetLineColor(kCyan+3);
      if(plotList[iPlot].first->rie_number_=="12920") plotList[iPlot].second->SetLineColor(kCyan-5);
      if(plotList[iPlot].first->rie_number_=="13041") plotList[iPlot].second->SetLineColor(kCyan-7);
      if(plotList[iPlot].first->rie_number_=="13047") plotList[iPlot].second->SetLineColor(kCyan-6);


      if(plotList[iPlot].first->rie_number_=="13042") plotList[iPlot].second->SetLineColor(kBlue+1);
      if(plotList[iPlot].first->rie_number_=="13048") plotList[iPlot].second->SetLineColor(kBlue+3);
      if(plotList[iPlot].first->rie_number_=="13383") plotList[iPlot].second->SetLineColor(kBlue-2);
      if(plotList[iPlot].first->rie_number_=="13473") plotList[iPlot].second->SetLineColor(kBlue-5);
      if(plotList[iPlot].first->rie_number_=="14649") plotList[iPlot].second->SetLineColor(kBlue-7);


      if(plotList[iPlot].first->rie_number_=="6415")  plotList[iPlot].second->SetLineColor(kMagenta+1);
      if(plotList[iPlot].first->rie_number_=="6714")  plotList[iPlot].second->SetLineColor(kMagenta+3);
      if(plotList[iPlot].first->rie_number_=="7205")  plotList[iPlot].second->SetLineColor(kMagenta-5);
      if(plotList[iPlot].first->rie_number_=="7603")  plotList[iPlot].second->SetLineColor(kMagenta-7);
      if(plotList[iPlot].first->rie_number_=="8127")  plotList[iPlot].second->SetLineColor(kMagenta-10);


      if(plotList[iPlot].first->rie_number_=="14753") plotList[iPlot].second->SetLineColor(kRed+1);
      if(plotList[iPlot].first->rie_number_=="14765") plotList[iPlot].second->SetLineColor(kRed+3);
      if(plotList[iPlot].first->rie_number_=="5620")  plotList[iPlot].second->SetLineColor(kRed-1);
      if(plotList[iPlot].first->rie_number_=="8172")  plotList[iPlot].second->SetLineColor(kRed-5);
      if(plotList[iPlot].first->rie_number_=="8605")  plotList[iPlot].second->SetLineColor(kRed-7);
      
    }
  }


  //
  // Draw Overlay plots for all vpts in the same run for this variable
  //
  TCanvas *c1 = new TCanvas("c1", "c1" , 10, 10, 1000, 600);
  c1->SetGrid();   

  TMultiGraph *mg = new TMultiGraph();

  /*
  TString overlayTitle = "";
  overlayTitle += "CMS Preliminary, ";

  if(plotList[0].first->site_==site::brunel)     overlayTitle += "Brunel site, ";
  if(plotList[0].first->site_==site::uva)        overlayTitle += "U.Va. site, ";

  if(plotList[0].first->run_num_==run_num::run1) overlayTitle += "Run 1, ";
  if(plotList[0].first->run_num_==run_num::run2) overlayTitle += "Run 2, ";
  if(plotList[0].first->run_num_==run_num::run3) overlayTitle += "Run 3, ";
  if(plotList[0].first->run_num_==run_num::run4) overlayTitle += "Run 4, ";
  if(plotList[0].first->run_num_==run_num::run5) overlayTitle += "Run 5, ";
  if(plotList[0].first->run_num_==run_num::run6) overlayTitle += "Run 6, ";

  overlayTitle += "Overlays - ";
  overlayTitle += plot.title;
 
  TString extra_title = "";
  if(plot.applyAveraging) {
    extra_title += ", Averaged over ";
    extra_title += plot.numToAvg*2;
    extra_title += " points";
  }
  if(plot.applyNormalize) extra_title += ", Normalized to Start of Run"; 
  
  overlayTitle += extra_title;
  */
  TString overlayTitle = plot.title;

  mg->SetTitle(0); // Draw Title with TLatex later


  // Declare Legend
  TLegend *leg;
  if((int)plotList.size()>5) leg = new TLegend(0.13,0.65,0.90,0.895);
  else                       leg = new TLegend(0.13,0.85,0.90,0.895);
   
  leg->SetTextAlign(12);
  leg->SetTextSize(0.027);
  leg->SetNColumns(5);
  leg->SetFillStyle(1001);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  

  // Add plots to overlay
  double yMax=0.0;
  for(int i=0; i<(int)plotList.size(); i++){
    TGraphErrors *gr1 = plotList[i].second; 
    gr1->SetTitle(0);
    TPaveStats *stats = (TPaveStats*)gr1->FindObject("stats");
    if(stats)stats->Delete();
    //gr1->SetMarkerStyle(20);
    //gr1->SetMarkerSize(0.25);
    //gr1->SetLineColor(plotList[i].first->color_);
    //gr1->SetMarkerColor(plotList[i].first->color_);
    //gr1->SetFillColor(plotList[i].first->color_);
    gr1->SetMarkerColor(gr1->GetLineColor());
    gr1->SetFillColor(gr1->GetLineColor());
    yMax = std::max(yMax, gr1->GetHistogram()->GetMaximum()); 
    mg->Add(gr1);
    leg->AddEntry(gr1, "vpt "+plotList[i].first->rie_number_, "flp"); 
  }
  if(yMax>0.0){
    if((int)plotList.size()>5) mg->SetMaximum(1.3*yMax);
    else                       mg->SetMaximum(1.1*yMax);
  }

  // Draw All the Things!
  mg->Draw("AP");
  leg->Draw();
  
  if(plot.applyFit){
    for(int i=0; i<(int)plotList.size(); i++){
      if( plot.yBranch.Contains("orange_reference_anode") ){
	if( plot.applyNormalize ){
	  plotList[i].first->fit_orng_norm_->Draw("same");
	}
	else{
	  plotList[i].first->fit_orng_->Draw("same");
	}
      }
      else{
	if( plot.applyNormalize ){
	  plotList[i].first->fit_blue_norm_->Draw("same");
	}
	else{
	  plotList[i].first->fit_blue_->Draw("same");
	}
      }
    }
  }

  // Axis Attributes must be set after TMultiGraph is drawn
  mg->GetXaxis()->SetTitle(plot.xAxisTitle);
  mg->GetYaxis()->SetTitle(plot.yAxisTitle);

  TLatex title;
  title.SetNDC();
  title.SetTextAlign(21);
  title.SetTextFont(42);
  title.SetTextSize(0.032);
  title.DrawLatex(0.5, 0.95, overlayTitle);
      

  //
  // Create TString to save output
  //
  TString saveMe = "../plots/";
     
  if(plotList[0].first->site_==site::brunel) saveMe += "brunel_";
  if(plotList[0].first->site_==site::uva)    saveMe += "uva_";
 
  if(groupDescription==""){
    if(plotList[0].first->run_num_==run_num::run1) saveMe += "run1_";
    if(plotList[0].first->run_num_==run_num::run2) saveMe += "run2_";
    if(plotList[0].first->run_num_==run_num::run3) saveMe += "run3_";
    if(plotList[0].first->run_num_==run_num::run4) saveMe += "run4_";
    if(plotList[0].first->run_num_==run_num::run5) saveMe += "run5_";
    if(plotList[0].first->run_num_==run_num::run6) saveMe += "run6_";
  }
  else{
    saveMe += groupDescription + "_";
  }
       
  saveMe += "Overlay_";

  TString saveMeY = plot.yBranch;
  saveMeY.ReplaceAll("(", "");
  saveMeY.ReplaceAll(")", "");
  saveMeY.ReplaceAll("/", "_div_");
  saveMeY.ReplaceAll("\\*", "_times_");

  TString saveMeX = plot.xBranch;
  saveMeX.ReplaceAll("(", "");
  saveMeX.ReplaceAll(")", "");
  saveMeX.ReplaceAll("/", "_div_");
  saveMeX.ReplaceAll("\\*", "_times_");

  saveMe += "__" + saveMeY;
  saveMe += "__vs__";
  saveMe += saveMeX;
  if(plot.applyAveraging){
    saveMe += "__rolling_average_of_";
    saveMe += plot.numToAvg*2.0;
    saveMe += "pts";
  }
  if(plot.applyNormalize) saveMe += "__normalized_to_start_of_run";
  if(plot.applyFit)       saveMe += "__fitted_with_" + plot.formulaName;
  
  saveMe.ReplaceAll(" ", "_");
  
  if(verbose) cout << "Saving Plot: " << saveMe << endl;

  TString saveMeC   = saveMe + ".C";
  c1->SaveAs(saveMeC,   ""); 
  
  //TString saveMeGif = saveMe + ".gif";
  //c1->SaveAs(saveMeGif, "");
      
  //TString saveMePdf = saveMe + ".pdf";
  //c1->SaveAs(saveMePdf, "");
  
  TString saveMePng = saveMe + ".png";
  c1->SaveAs(saveMePng, "");

  if(analysis_type_ == analysis_type::plot){
    plot_file_->WriteObject(c1, saveMe);
  }
  if(analysis_type_ == analysis_type::fit){
    fit_file_->WriteObject(c1, saveMe);
  }
  
  c1->~TCanvas();

  return;
}
    


//_____________________________________________________________________________
//
// Draw Fit Result Histograms
//
void vpt_analysis::get_fit_result_plots(){
  
  //
  // Global Atributes
  //
  gROOT->ForceStyle(0);
  gStyle->SetOptStat(111111);
  gStyle->SetHistLineWidth(3);
  gStyle->SetTitleAlign(23);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFillColor(0);
    

  //
  // Draw Histograms for all of the Fit Results
  //


  //
  // Blue Reference Fit, Pedestal
  //
  TCanvas *can_blue_ref_fit_c = new TCanvas("can_blue_ref_fit_c", "can_blue_ref_fit_c" , 10, 10, 1000, 600);
  can_blue_ref_fit_c->SetGrid();
  TH1F *h_blue_ref_fit_c = new TH1F("h_blue_ref_fit_c", "Blue Reference Illumination, Fit Results for Pedastal Parameter;Pedastal", 30, -0.5e-9, 4.5e-9);
  h_blue_ref_fit_c->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_c_.size(); i++) h_blue_ref_fit_c->Fill(v_blue_ref_fit_c_[i]);
  h_blue_ref_fit_c->Draw("hist goff");
  can_blue_ref_fit_c->SaveAs("../plots/h_fit_results__blue_reference_led__pedestal.png");
  can_blue_ref_fit_c->~TCanvas();


  //
  // Blue Reference Fit, Fast Exponential Amplitude
  //
  TCanvas *can_blue_ref_fit_a1 = new TCanvas("can_blue_ref_fit_a1", "can_blue_ref_fit_a1" , 10, 10, 1000, 600);
  can_blue_ref_fit_a1->SetGrid();   
  TH1F* h_blue_ref_fit_a1 = new TH1F("h_blue_ref_fit_a1", "Blue Reference Illumination, Fit Results for Amplitude of Fast Exponential;\\Alpha_{1}", 30, -0.5e-9, 2e-9);
  h_blue_ref_fit_a1->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_a1_.size(); i++) h_blue_ref_fit_a1->Fill(v_blue_ref_fit_a1_[i]);
  h_blue_ref_fit_a1->Draw("hist goff");
  can_blue_ref_fit_a1->SaveAs("../plots/h_fit_results__blue_reference_led__amplitude_fast_exp.png");
  can_blue_ref_fit_a1->~TCanvas();

  
  //
  // Blue Reference Fit, Fast Exponential Time Constant
  //
  TCanvas *can_blue_ref_fit_t1 = new TCanvas("can_blue_ref_fit_t1", "can_blue_ref_fit_t1" , 10, 10, 1000, 600);
  can_blue_ref_fit_t1->SetGrid();   
  TH1F *h_blue_ref_fit_t1 = new TH1F("h_blue_ref_fit_t1", "Blue Reference Illumination, Fit Results for Time Constant of Fast Exponential;|\\tau_{1}|", 50, 0.0, 0.03);
  h_blue_ref_fit_t1->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_t1_.size(); i++) h_blue_ref_fit_t1->Fill(fabs(v_blue_ref_fit_t1_[i]));
  h_blue_ref_fit_t1->Draw("hist goff");
  //gPad->SetLogx();
  can_blue_ref_fit_t1->SaveAs("../plots/h_fit_results__blue_reference_led__time_const_fast_exp.png");
  can_blue_ref_fit_t1->~TCanvas();

  
  //
  // Blue Reference Fit, Slow Exponential Amplitude
  //
  TCanvas *can_blue_ref_fit_a2 = new TCanvas("can_blue_ref_fit_a2", "can_blue_ref_fit_a2" , 10, 10, 1000, 600);
  can_blue_ref_fit_a2->SetGrid();  
  TH1F *h_blue_ref_fit_a2 = new TH1F("h_blue_ref_fit_a2", "Blue Reference Illumination, Fit Results for Amplitude of Slow Exponential;\\Alpha_{2}", 30, -0.5e-9, 2e-9);
  h_blue_ref_fit_a2->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_a2_.size(); i++) h_blue_ref_fit_a2->Fill(v_blue_ref_fit_a2_[i]);
  h_blue_ref_fit_a2->Draw("hist goff");
  can_blue_ref_fit_a2->SaveAs("../plots/h_fit_results__blue_reference_led__amplitude_slow_exp.png");
  can_blue_ref_fit_a2->~TCanvas();


  //
  // Blue Reference Fit, Slow Exponential Time Constant
  //
  TCanvas *can_blue_ref_fit_t2 = new TCanvas("can_blue_ref_fit_t2", "can_blue_ref_fit_t2" , 10, 10, 1000, 600);
  can_blue_ref_fit_t2->SetGrid();  
  TH1F *h_blue_ref_fit_t2 = new TH1F("h_blue_ref_fit_t2", "Blue Reference Illumination, Fit Results for Time Constant of Slow Exponential;|\\tau_{2}|", 50, 0.0, 0.03);
  h_blue_ref_fit_t2->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_t2_.size(); i++) h_blue_ref_fit_t2->Fill(fabs(v_blue_ref_fit_t2_[i]));
  h_blue_ref_fit_t2->Draw("hist goff");
  //gPad->SetLogx();
  can_blue_ref_fit_t2->SaveAs("../plots/h_fit_results__blue_reference_led__time_const_slow_exp.png");
  can_blue_ref_fit_t2->~TCanvas();


  //
  // Blue Reference Fit, All Time Constants
  //
  TCanvas *can_blue_ref_fit_all_t = new TCanvas("can_blue_ref_fit_all_t", "can_blue_ref_fit_all_t" , 10, 10, 1000, 600);
  can_blue_ref_fit_all_t->SetGrid();
  TH1F *h_blue_ref_fit_all_t = new TH1F("h_blue_ref_fit_all_t", "Blue Reference Illumination, Fit Results for Time Constant of Both Exponentials;|\\tau_{1,2}|", 50, 0.0, 0.03);
  h_blue_ref_fit_all_t->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_all_t_.size(); i++) h_blue_ref_fit_all_t->Fill(fabs(v_blue_ref_fit_all_t_[i]));
  h_blue_ref_fit_all_t->Draw("hist goff");
  //gPad->SetLogx();
  can_blue_ref_fit_all_t->SaveAs("../plots/h_fit_results__blue_reference_led__time_const_both_exp.png");
  can_blue_ref_fit_all_t->~TCanvas();


  //
  // Blue Reference Fit, Chi^2/NDF
  //
  TCanvas *can_blue_ref_fit_chi2 = new TCanvas("can_blue_ref_fit_chi2", "can_blue_ref_fit_chi2" , 10, 10, 1000, 600);
  can_blue_ref_fit_chi2->SetGrid();   
  TH1F *h_blue_ref_fit_chi2 = new TH1F("h_blue_ref_fit_chi2",  "Blue Reference Illumination, Fit Results for \\chi^{2}/NDF;\\chi^{2}/NDF", 20, 0, 10.0);
  h_blue_ref_fit_chi2->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_chi2_.size(); i++) h_blue_ref_fit_chi2->Fill(v_blue_ref_fit_chi2_[i]);
  h_blue_ref_fit_chi2->Draw("hist goff");
  can_blue_ref_fit_chi2->SaveAs("../plots/h_fit_results__blue_reference_led__chi2_div_ndf.png");
  can_blue_ref_fit_chi2->~TCanvas();
  

  //
  // Blue Reference Fit, %drop off
  //
  TCanvas *can_blue_ref_fit_drop = new TCanvas("can_blue_ref_fit_drop", "can_blue_ref_fit_drop" , 10, 10, 1000, 600);
  can_blue_ref_fit_drop->SetGrid();   
  TH1F *h_blue_ref_fit_drop = new TH1F("h_blue_ref_fit_drop",  "Blue Reference Illumination, Fit Results for Percentage Drop-Off;Percentage Drop-Off", 20, 0, 100.0);
  h_blue_ref_fit_drop->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_blue_ref_fit_drop_.size(); i++) h_blue_ref_fit_drop->Fill(v_blue_ref_fit_drop_[i]);
  h_blue_ref_fit_drop->Draw("hist goff");
  can_blue_ref_fit_drop->SaveAs("../plots/h_fit_results__blue_reference_led__percentage_dropOff.png");
  can_blue_ref_fit_drop->~TCanvas();


  //
  // Orange Reference Fit, Pedastal
  //
  TCanvas *can_orng_ref_fit_c = new TCanvas("can_orng_ref_fit_c", "can_orng_ref_fit_c" , 10, 10, 1000, 600);
  can_orng_ref_fit_c->SetGrid();   
  TH1F *h_orng_ref_fit_c = new TH1F("h_orng_ref_fit_c", "Orange Reference Illumination, Fit Results for Pedastal Parameter;Pedastal", 30, -0.5e-9, 1e-9);
  h_orng_ref_fit_c->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_c_.size(); i++) h_orng_ref_fit_c->Fill(v_orng_ref_fit_c_[i]);
  h_orng_ref_fit_c->Draw("hist goff");
  can_orng_ref_fit_c->SaveAs("../plots/h_fit_results__orng_reference_led__pedestal.png");
  can_orng_ref_fit_c->~TCanvas();


  //
  // Orange Reference Fit, Fast Exponential Amplitude 
  //
  TCanvas *can_orng_ref_fit_a1 = new TCanvas("can_orng_ref_fit_a1", "can_orng_ref_fit_a1" , 10, 10, 1000, 600);
  can_orng_ref_fit_a1->SetGrid(); 
  TH1F *h_orng_ref_fit_a1 = new TH1F("h_orng_ref_fit_a1", "Orange Reference Illumination, Fit Results for Amplitude of Fast Exponential;\\Alpha_{1}", 30, -0.5e-9, 1e-9);
  h_orng_ref_fit_a1->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_a1_.size(); i++) h_orng_ref_fit_a1->Fill(v_orng_ref_fit_a1_[i]);
  h_orng_ref_fit_a1->Draw("hist goff");
  can_orng_ref_fit_a1->SaveAs("../plots/h_fit_results__orng_reference_led__amplitude_fast_exp.png");
  can_orng_ref_fit_a1->~TCanvas();


  //
  // Orange Reference Fit, Fast Exponential Time Constant
  //
  TCanvas *can_orng_ref_fit_t1 = new TCanvas("can_orng_ref_fit_t1", "can_orng_ref_fit_t1" , 10, 10, 1000, 600);
  can_orng_ref_fit_t1->SetGrid();   
  TH1F *h_orng_ref_fit_t1 = new TH1F("h_orng_ref_fit_t1", "Orange Reference Illumination, Fit Results for Time Constant of Fast Exponential;|\\tau_{1}|", 50, 0.0, 0.03);
  h_orng_ref_fit_t1->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_t1_.size(); i++) h_orng_ref_fit_t1->Fill(fabs(v_orng_ref_fit_t1_[i]));
  h_orng_ref_fit_t1->Draw("hist goff");
  can_orng_ref_fit_t1->SaveAs("../plots/h_fit_results__orng_reference_led__time_const_fast_exp.png");
  can_orng_ref_fit_t1->~TCanvas();


  //
  // Orange Reference Fit, Slow Exponential Amplitude
  //
  TCanvas *can_orng_ref_fit_a2 = new TCanvas("can_orng_ref_fit_a2", "can_orng_ref_fit_a2" , 10, 10, 1000, 600);
  can_orng_ref_fit_a2->SetGrid();   
  TH1F *h_orng_ref_fit_a2 = new TH1F("h_orng_ref_fit_a2", "Orange Reference Illumination, Fit Results for Amplitude of Slow Exponential;\\Alpha_{2}", 20, -0.5e-9, 1e-9);
  h_orng_ref_fit_a2->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_a2_.size(); i++) h_orng_ref_fit_a2->Fill(v_orng_ref_fit_a2_[i]);
  h_orng_ref_fit_a2->Draw("hist goff");
  can_orng_ref_fit_a2->SaveAs("../plots/h_fit_results__orng_reference_led__amplitude_slow_exp.png");
  can_orng_ref_fit_a2->~TCanvas();


  //
  // Orange Reference Fit, Slow Exponential Time Constant
  //
  TCanvas *can_orng_ref_fit_t2 = new TCanvas("can_orng_ref_fit_t2", "can_orng_ref_fit_t2" , 10, 10, 1000, 600);
  can_orng_ref_fit_t2->SetGrid();
  TH1F *h_orng_ref_fit_t2 = new TH1F("h_orng_ref_fit_t2", "Orange Reference Illumination, Fit Results for Time Constant of Slow Exponential;|\\tau_{2}|", 50, 0.0, 0.03);
  h_orng_ref_fit_t2->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_t2_.size(); i++) h_orng_ref_fit_t2->Fill(fabs(v_orng_ref_fit_t2_[i]));
  h_orng_ref_fit_t2->Draw("hist goff");
  can_orng_ref_fit_t2->SaveAs("../plots/h_fit_results__orng_reference_led__time_const_slow_exp.png");
  can_orng_ref_fit_t2->~TCanvas();


  //
  // Orange Reference Fit, All Time Constants
  //
  TCanvas *can_orng_ref_fit_all_t = new TCanvas("can_orng_ref_fit_all_t", "can_orng_ref_fit_all_t" , 10, 10, 1000, 600);
  can_orng_ref_fit_all_t->SetGrid();   
  TH1F *h_orng_ref_fit_all_t = new TH1F("h_orng_ref_fit_all_t", "Orange Reference Illumination, Fit Results for Time Constant of Both Exponentials;|\\tau_{1,2}|", 50, 0.0, 0.03);
  h_orng_ref_fit_all_t->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_all_t_.size(); i++) h_orng_ref_fit_all_t->Fill(fabs(v_orng_ref_fit_all_t_[i]));
  h_orng_ref_fit_all_t->Draw("hist goff");
  can_orng_ref_fit_all_t->SaveAs("../plots/h_fit_results__orng_reference_led__time_const_both_exp.png");
  can_orng_ref_fit_all_t->~TCanvas();


  // 
  // Orange Reference Fit, Chi2/NDF
  //
  TCanvas *can_orng_ref_fit_chi2 = new TCanvas("can_orng_ref_fit_chi2", "can_orng_ref_fit_chi2" , 10, 10, 1000, 600);
  can_orng_ref_fit_chi2->SetGrid(); 
  TH1F *h_orng_ref_fit_chi2 = new TH1F("h_orng_ref_fit_chi2", "Orange Reference Illumination, Fit Results for \\chi^{2}/NDF;\\chi^{2}/NDF", 60, 0.0, 30.0);
  h_orng_ref_fit_chi2->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_chi2_.size(); i++) h_orng_ref_fit_chi2->Fill(v_orng_ref_fit_chi2_[i]);
  h_orng_ref_fit_chi2->Draw("hist goff");
  can_orng_ref_fit_chi2->SaveAs("../plots/h_fit_results__orng_reference_led__chi2_div_ndf.png");
  can_orng_ref_fit_chi2->~TCanvas();


  //
  // Orange Reference Fit, %drop off
  //
  TCanvas *can_orng_ref_fit_drop = new TCanvas("can_orng_ref_fit_drop", "can_orng_ref_fit_drop" , 10, 10, 1000, 600);
  can_orng_ref_fit_drop->SetGrid();   
  TH1F *h_orng_ref_fit_drop = new TH1F("h_orng_ref_fit_drop",  "Orange Reference Illumination, Fit Results for Percentage Drop-Off;Percentage Drop-Off", 20, 0, 100.0);
  h_orng_ref_fit_drop->SetDirectory(fit_file_);
  for(int i=0; i<(int)v_orng_ref_fit_drop_.size(); i++) h_orng_ref_fit_drop->Fill(v_orng_ref_fit_drop_[i]);
  h_orng_ref_fit_drop->Draw("hist goff");
  can_orng_ref_fit_drop->SaveAs("../plots/h_fit_results__orng_reference_led__percentage_dropOff.png");
  can_orng_ref_fit_drop->~TCanvas();




  //
  // Create a table summarizing kinFit performance
  //

  FILE *file;
 
  // open latex file for mergedJet table
  TString fName = "../plots/vpt_fit_results_table__blue_led.tex";
  file = fopen(fName, "w");

  // Print Beginning of laTeX document
  fprintf(file, "\\documentclass{article} \n");
  fprintf(file, "\\usepackage[landscape]{geometry} \n");
  fprintf(file, "\\usepackage{chngpage} \n");
  fprintf(file, "\n \n \\begin{document} \n \n");
    
  fprintf(file, "\\begin{table}[ht] \n");
  fprintf(file, "\\begin{adjustwidth}{-1.7in}{-1.7in} \n");
  fprintf(file, "  \\centering \n");
  fprintf(file, "  \\noindent \n");
  fprintf(file, "  \\small \n");
    
  fprintf(file, "    \\caption{Fit Results for VPT Conditioning Studies at U.Va. and Brunel, Blue Reference LED} \n");
  fprintf(file, "    \\label{tab:Table 1} \n");

  fprintf(file, "    \\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \\hline \n");
  
  fprintf(file, "Run Site & RIE Number & $\\%%$ Drop & $\\chi^2/NDF$ & Pedestal & Fast exp Amplitude & Fast exp $\\tau$ & Slow exp Amplitude & Slow exp $\\tau$ ");
  fprintf(file, " \\");
  fprintf(file, "\\");
  fprintf(file, " \\hline \n \n");

  for(int iVpt=0; iVpt<(int)v_blue_ref_fit_rieNum_.size(); iVpt++){

    if(v_blue_ref_fit_rieNum_[iVpt]=="947") fprintf(file, "$Brunel$");
    else                                    fprintf(file, "$U.Va.$");

    fprintf(file, " & %s ",   v_blue_ref_fit_rieNum_[iVpt].Data());

    fprintf(file, " & %2.1f", v_blue_ref_fit_drop_[iVpt]);

    fprintf(file, " & %2.2e", v_blue_ref_fit_chi2_[iVpt]);

    fprintf(file, " & %2.2e", v_blue_ref_fit_c_[iVpt]);

    fprintf(file, " & %2.2e", v_blue_ref_fit_a1_[iVpt]);

    fprintf(file, " & %2.2e", v_blue_ref_fit_t1_[iVpt]);

    fprintf(file, " & %2.2e", v_blue_ref_fit_a2_[iVpt]);

    fprintf(file, " & %2.2e", v_blue_ref_fit_t2_[iVpt]);

    fprintf(file, "\\"); fprintf(file, "\\"); fprintf(file, " \\hline \n");

  }

  // get average for each column
  fprintf(file, "Any & Average ");

  // Avg % drop
  double avg_drop_blue=0.0, avg_drop_blue_err=0.0;
  for(int i=0; i<(int)v_blue_ref_fit_drop_.size(); i++){
    avg_drop_blue     += v_blue_ref_fit_drop_[i];
    avg_drop_blue_err += pow(v_blue_ref_fit_drop_[i], 2);
  }
  if(avg_drop_blue!=0) avg_drop_blue /= (double)v_blue_ref_fit_drop_.size();
  if(avg_drop_blue_err!=0){
    avg_drop_blue_err /= (double)v_blue_ref_fit_drop_.size();
    avg_drop_blue_err -= pow( avg_drop_blue, 2);
    avg_drop_blue_err  = sqrt(avg_drop_blue_err);
    avg_drop_blue_err /= sqrt(v_blue_ref_fit_drop_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_drop_blue, avg_drop_blue_err);

  // Avg Chi2
  double avg_chi2_blue=0.0, avg_chi2_blue_err=0.0;
  for(int i=0; i<(int)v_blue_ref_fit_chi2_.size(); i++){
    avg_chi2_blue     += v_blue_ref_fit_chi2_[i];
    avg_chi2_blue_err += pow(v_blue_ref_fit_chi2_[i], 2);
  }
  if(avg_chi2_blue!=0) avg_chi2_blue /= (double)v_blue_ref_fit_chi2_.size();
  if(avg_chi2_blue_err!=0){
    avg_chi2_blue_err /= (double)v_blue_ref_fit_chi2_.size();
    avg_chi2_blue_err -= pow( avg_chi2_blue, 2);
    avg_chi2_blue_err  = sqrt(avg_chi2_blue_err);
    avg_chi2_blue_err /= sqrt(v_blue_ref_fit_chi2_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_chi2_blue, avg_chi2_blue_err);


  // Avg Pedestal
  double avg_c_blue=0.0, avg_c_blue_err=0.0;
  for(int i=0; i<(int)v_blue_ref_fit_c_.size(); i++){
    avg_c_blue     += v_blue_ref_fit_c_[i];
    avg_c_blue_err += pow(v_blue_ref_fit_c_[i], 2);
  }
  if(avg_c_blue!=0) avg_c_blue /= (double)v_blue_ref_fit_c_.size();
  if(avg_c_blue_err!=0){
    avg_c_blue_err /= (double)v_blue_ref_fit_c_.size();
    avg_c_blue_err -= pow( avg_c_blue, 2);
    avg_c_blue_err  = sqrt(avg_c_blue_err);
    avg_c_blue_err /= sqrt(v_blue_ref_fit_c_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_c_blue, avg_c_blue_err);


  // Avg Fast Amplitude
  double avg_a1_blue=0.0, avg_a1_blue_err=0.0;
  for(int i=0; i<(int)v_blue_ref_fit_a1_.size(); i++){
    avg_a1_blue     += v_blue_ref_fit_a1_[i];
    avg_a1_blue_err += pow(v_blue_ref_fit_a1_[i], 2);
  }
  if(avg_a1_blue!=0) avg_a1_blue /= (double)v_blue_ref_fit_a1_.size();
  if(avg_a1_blue_err!=0){
    avg_a1_blue_err /= (double)v_blue_ref_fit_a1_.size();
    avg_a1_blue_err -= pow( avg_a1_blue, 2);
    avg_a1_blue_err  = sqrt(avg_a1_blue_err);
    avg_a1_blue_err /= sqrt(v_blue_ref_fit_a1_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_a1_blue, avg_a1_blue_err);

  
  // Avg Fast Time Constant
  double avg_t1_blue=0.0, avg_t1_blue_err=0.0;
  for(int i=0; i<(int)v_blue_ref_fit_t1_.size(); i++){
    avg_t1_blue     += v_blue_ref_fit_t1_[i];
    avg_t1_blue_err += pow(v_blue_ref_fit_t1_[i], 2);
  }
  if(avg_t1_blue!=0) avg_t1_blue /= (double)v_blue_ref_fit_t1_.size();
  if(avg_t1_blue_err!=0){
    avg_t1_blue_err /= (double)v_blue_ref_fit_t1_.size();
    avg_t1_blue_err -= pow( avg_t1_blue, 2);
    avg_t1_blue_err  = sqrt(avg_t1_blue_err);
    avg_t1_blue_err /= sqrt(v_blue_ref_fit_t1_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_t1_blue, avg_t1_blue_err);


  // Avg Slow Amplitude
  double avg_a2_blue=0.0, avg_a2_blue_err=0.0;
  for(int i=0; i<(int)v_blue_ref_fit_a2_.size(); i++){
    avg_a2_blue     += v_blue_ref_fit_a2_[i];
    avg_a2_blue_err += pow(v_blue_ref_fit_a2_[i], 2);
  }
  if(avg_a2_blue!=0) avg_a2_blue /= (double)v_blue_ref_fit_a2_.size();
  if(avg_a2_blue_err!=0){
    avg_a2_blue_err /= (double)v_blue_ref_fit_a2_.size();
    avg_a2_blue_err -= pow( avg_a2_blue, 2);
    avg_a2_blue_err  = sqrt(avg_a2_blue_err);
    avg_a2_blue_err /= sqrt(v_blue_ref_fit_a2_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_a2_blue, avg_a2_blue_err);


  // Avg Slow Time Constant
  double avg_t2_blue=0.0, avg_t2_blue_err=0.0;
  for(int i=0; i<(int)v_blue_ref_fit_t2_.size(); i++){
    avg_t2_blue     += v_blue_ref_fit_t2_[i];
    avg_t2_blue_err += pow(v_blue_ref_fit_t2_[i], 2);
  }
  if(avg_t2_blue!=0) avg_t2_blue /= (double)v_blue_ref_fit_t2_.size();
  if(avg_t2_blue_err!=0){
    avg_t2_blue_err /= (double)v_blue_ref_fit_t2_.size();
    avg_t2_blue_err -= pow( avg_t2_blue, 2);
    avg_t2_blue_err  = sqrt(avg_t2_blue_err);
    avg_t2_blue_err /= sqrt(v_blue_ref_fit_t2_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_t2_blue, avg_t2_blue_err);


  fprintf(file, "\\"); fprintf(file, "\\"); fprintf(file, " \\hline \n");



  //
  // Format end of table
  //
  fprintf(file, "    \\end{tabular} \n");
  fprintf(file, "  \\end{adjustwidth} \n");
  fprintf(file, "\\end{table} \n \n \n");
  fprintf(file, "\\end{document} \n \n");
  
  fclose(file);
  
  cout << "  Table of blue reference fit performance writted to: " << fName << endl;




  // open latex file for mergedJet table
  fName = "../plots/vpt_fit_results_table__orng_led.tex";
  file = fopen(fName, "w");

  // Print Beginning of laTeX document
  fprintf(file, "\\documentclass{article} \n");
  fprintf(file, "\\usepackage[landscape]{geometry} \n");
  fprintf(file, "\\usepackage{chngpage} \n");
  fprintf(file, "\n \n \\begin{document} \n \n");
    
  fprintf(file, "\\begin{table}[ht] \n");
  fprintf(file, "\\begin{adjustwidth}{-1.7in}{-1.7in} \n");
  fprintf(file, "  \\centering \n");
  fprintf(file, "  \\noindent \n");
  fprintf(file, "  \\small \n");
    
  fprintf(file, "    \\caption{Fit Results for VPT Conditioning Studies at U.Va., Orange LED} \n");
  fprintf(file, "    \\label{tab:Table 1} \n");

  fprintf(file, "    \\begin{tabular}{|c|c|c|c|c|c|c|c|c|} \\hline \n");
  
  fprintf(file, "Run Site & RIE Number & $\\%%$ Drop & $\\chi^2/NDF$ & Pedestal & Fast exp Amplitude &  Fast exp $\\tau$  & Slow exp Amplitude &  Slow exp $\\tau$  ");
  fprintf(file, " \\");
  fprintf(file, "\\");
  fprintf(file, " \\hline \n \n");

  for(int iVpt=0; iVpt<(int)v_orng_ref_fit_rieNum_.size(); iVpt++){

    if(v_orng_ref_fit_rieNum_[iVpt]=="947") fprintf(file, "$Brunel$");
    else                                    fprintf(file, "$U.Va.$");

    fprintf(file, " & %s ",   v_orng_ref_fit_rieNum_[iVpt].Data());

    fprintf(file, " & %2.1f", v_orng_ref_fit_drop_[iVpt]);

    fprintf(file, " & %2.2e", v_orng_ref_fit_chi2_[iVpt]);

    fprintf(file, " & %2.2e", v_orng_ref_fit_c_[iVpt]);

    fprintf(file, " & %2.2e", v_orng_ref_fit_a1_[iVpt]);

    fprintf(file, " & %2.2e", v_orng_ref_fit_t1_[iVpt]);

    fprintf(file, " & %2.2e", v_orng_ref_fit_a2_[iVpt]);

    fprintf(file, " & %2.2e", v_orng_ref_fit_t2_[iVpt]);

    fprintf(file, "\\"); fprintf(file, "\\"); fprintf(file, " \\hline \n");

  }

  
  // get average for each column
  fprintf(file, "Any & Average ");

  // Avg % drop
  double avg_drop_orng=0.0, avg_drop_orng_err=0.0;
  for(int i=0; i<(int)v_orng_ref_fit_drop_.size(); i++){
    avg_drop_orng     += v_orng_ref_fit_drop_[i];
    avg_drop_orng_err += pow(v_orng_ref_fit_drop_[i], 2);
  }
  if(avg_drop_orng!=0) avg_drop_orng /= (double)v_orng_ref_fit_drop_.size();
  if(avg_drop_orng_err!=0){
    avg_drop_orng_err /= (double)v_orng_ref_fit_drop_.size();
    avg_drop_orng_err -= pow( avg_drop_orng, 2);
    avg_drop_orng_err  = sqrt(avg_drop_orng_err);
    avg_drop_orng_err /= sqrt(v_orng_ref_fit_drop_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_drop_orng, avg_drop_orng_err);

  // Avg Chi2
  double avg_chi2_orng=0.0, avg_chi2_orng_err=0.0;
  for(int i=0; i<(int)v_orng_ref_fit_chi2_.size(); i++){
    avg_chi2_orng     += v_orng_ref_fit_chi2_[i];
    avg_chi2_orng_err += pow(v_orng_ref_fit_chi2_[i], 2);
  }
  if(avg_chi2_orng!=0) avg_chi2_orng /= (double)v_orng_ref_fit_chi2_.size();
  if(avg_chi2_orng_err!=0){
    avg_chi2_orng_err /= (double)v_orng_ref_fit_chi2_.size();
    avg_chi2_orng_err -= pow( avg_chi2_orng, 2);
    avg_chi2_orng_err  = sqrt(avg_chi2_orng_err);
    avg_chi2_orng_err /= sqrt(v_orng_ref_fit_chi2_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_chi2_orng, avg_chi2_orng_err);


  // Avg Pedestal
  double avg_c_orng=0.0, avg_c_orng_err=0.0;
  for(int i=0; i<(int)v_orng_ref_fit_c_.size(); i++){
    avg_c_orng     += v_orng_ref_fit_c_[i];
    avg_c_orng_err += pow(v_orng_ref_fit_c_[i], 2);
  }
  if(avg_c_orng!=0) avg_c_orng /= (double)v_orng_ref_fit_c_.size();
  if(avg_c_orng_err!=0){
    avg_c_orng_err /= (double)v_orng_ref_fit_c_.size();
    avg_c_orng_err -= pow( avg_c_orng, 2);
    avg_c_orng_err  = sqrt(avg_c_orng_err);
    avg_c_orng_err /= sqrt(v_orng_ref_fit_c_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_c_orng, avg_c_orng_err);


  // Avg Fast Amplitude
  double avg_a1_orng=0.0, avg_a1_orng_err=0.0;
  for(int i=0; i<(int)v_orng_ref_fit_a1_.size(); i++){
    avg_a1_orng     += v_orng_ref_fit_a1_[i];
    avg_a1_orng_err += pow(v_orng_ref_fit_a1_[i], 2);
  }
  if(avg_a1_orng!=0) avg_a1_orng /= (double)v_orng_ref_fit_a1_.size();
  if(avg_a1_orng_err!=0){
    avg_a1_orng_err /= (double)v_orng_ref_fit_a1_.size();
    avg_a1_orng_err -= pow( avg_a1_orng, 2);
    avg_a1_orng_err  = sqrt(avg_a1_orng_err);
    avg_a1_orng_err /= sqrt(v_orng_ref_fit_a1_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_a1_orng, avg_a1_orng_err);

  
  // Avg Fast Time Constant
  double avg_t1_orng=0.0, avg_t1_orng_err=0.0;
  for(int i=0; i<(int)v_orng_ref_fit_t1_.size(); i++){
    avg_t1_orng     += v_orng_ref_fit_t1_[i];
    avg_t1_orng_err += pow(v_orng_ref_fit_t1_[i], 2);
  }
  if(avg_t1_orng!=0) avg_t1_orng /= (double)v_orng_ref_fit_t1_.size();
  if(avg_t1_orng_err!=0){
    avg_t1_orng_err /= (double)v_orng_ref_fit_t1_.size();
    avg_t1_orng_err -= pow( avg_t1_orng, 2);
    avg_t1_orng_err  = sqrt(avg_t1_orng_err);
    avg_t1_orng_err /= sqrt(v_orng_ref_fit_t1_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_t1_orng, avg_t1_orng_err);


  // Avg Slow Amplitude
  double avg_a2_orng=0.0, avg_a2_orng_err=0.0;
  for(int i=0; i<(int)v_orng_ref_fit_a2_.size(); i++){
    avg_a2_orng     += v_orng_ref_fit_a2_[i];
    avg_a2_orng_err += pow(v_orng_ref_fit_a2_[i], 2);
  }
  if(avg_a2_orng!=0) avg_a2_orng /= (double)v_orng_ref_fit_a2_.size();
  if(avg_a2_orng_err!=0){
    avg_a2_orng_err /= (double)v_orng_ref_fit_a2_.size();
    avg_a2_orng_err -= pow( avg_a2_orng, 2);
    avg_a2_orng_err  = sqrt(avg_a2_orng_err);
    avg_a2_orng_err /= sqrt(v_orng_ref_fit_a2_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_a2_orng, avg_a2_orng_err);


  // Avg Slow Time Constant
  double avg_t2_orng=0.0, avg_t2_orng_err=0.0;
  for(int i=0; i<(int)v_orng_ref_fit_t2_.size(); i++){
    avg_t2_orng     += v_orng_ref_fit_t2_[i];
    avg_t2_orng_err += pow(v_orng_ref_fit_t2_[i], 2);
  }
  if(avg_t2_orng!=0) avg_t2_orng /= (double)v_orng_ref_fit_t2_.size();
  if(avg_t2_orng_err!=0){
    avg_t2_orng_err /= (double)v_orng_ref_fit_t2_.size();
    avg_t2_orng_err -= pow( avg_t2_orng, 2);
    avg_t2_orng_err  = sqrt(avg_t2_orng_err);
    avg_t2_orng_err /= sqrt(v_orng_ref_fit_t2_.size() );
  }
  fprintf(file, " & %2.2e $\\pm$ %2.2e ", avg_t2_orng, avg_t2_orng_err);


  fprintf(file, "\\"); fprintf(file, "\\"); fprintf(file, " \\hline \n");



  //
  // Format end of table
  //
  fprintf(file, "    \\end{tabular} \n");
  fprintf(file, "  \\end{adjustwidth} \n");
  fprintf(file, "\\end{table} \n \n \n");
  fprintf(file, "\\end{document} \n \n");
  
  fclose(file);
  
  cout << "  Table of orange reference fit performance writted to: " << fName << endl;





  return;

}
  
 

//=============================================================================
//
//  Fin
//
//=============================================================================
