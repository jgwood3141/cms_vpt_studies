#include "../interface/vpt_analysis.h"

int vpt_analyzer(){

  // Declare Analysis Object
  vpt_analysis analyzer(analysis_type::analyze);

  // Get Raw Data
  analyzer.get_raw_data();
  
  // Extrapolate Dark Current
  analyzer.get_extrapolated_dark_current();
  
  // Get Pin Corrections
  analyzer.get_pin_corrections();

  // Correct Cathode Current
  analyzer.get_cathode_corrections();
  
  // Calculate Integrated Charge
  analyzer.get_integrated_charge();
  
  // Correct Anode Repsonse
  analyzer.get_anode_corrections();
  
  // Calculate Filter Discriminants
  analyzer.get_filter_results();

  // Make sure all branches are friends
  analyzer.make_friends();

  // Destructor called automatically on return
  
  return 0;
}
