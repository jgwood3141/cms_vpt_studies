// John Wood
// UVa HEP
// VPT Test Rig
//
// Plotting Macro
// vpt_plot.C

#include <vector>

#include "../interface/vpt_analysis.h"

int vpt_plots(){

  // Declare analysis object
  vpt_analysis analyzer(analysis_type::plot);
  
  //
  // Declare plots
  //
  plotInfo plot;
  vector<plotInfo> plotList;
  
  
  // Blue Reference LED VPT/PIN vs Integrated Q
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  //plotList.push_back(plot);
  plot.reset();

      
  // Blue Reference LED VPT/PIN vs Integrated Q, Averaged 10 pts
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Averaging(5);

  //plotList.push_back(plot);
  plot.reset();

  
      
  // Blue Reference LED VPT/PIN vs Integrated Q, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();


  // Blue Reference LED VPT/PIN vs Integrated Q, avg+normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Averaging(5);
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Reference LED VPT/PIN vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, VPT Anode Response vs Time";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Reference LED VPT/PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, VPT Anode Response vs Time";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();  

  
  
  // Blue Reference LED Anode vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode_raw";
  plot.yBranch_err = "blue_reference_anode_raw_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, Uncorrected VPT Anode Response vs Time";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response, Uncorrected [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Reference LED Anode vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode_raw";
  plot.yBranch_err = "blue_reference_anode_raw_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, Uncorrected VPT Anode Response vs Time";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response, Uncorrected [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Reference LED PIN vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_pin";
  plot.yBranch_err = "blue_reference_pin_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, PIN Response vs Time";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "PIN Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Reference LED PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_pin";
  plot.yBranch_err = "blue_reference_pin_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, PIN Response vs Time";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "PIN Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();
  

  // Blue Reference LED PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_pin_correction";
  plot.yBranch_err = "blue_reference_pin_correction_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Reference LED, PIN Correction vs Time";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "PIN Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Load LED VPT/PIN vs Integrated Q
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_anode";
  plot.yBranch_err = "blue_load_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED VPT/PIN vs Integrated Q, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_anode";
  plot.yBranch_err = "blue_load_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Cathode Current vs Integrated Q
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current";
  plot.yBranch_err = "blue_load_cathode_current_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Cathode Current vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current [Amperes/100ms Aperature]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Cathode Current vs Integrated Q, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current";
  plot.yBranch_err = "blue_load_cathode_current_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Cathode Current vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();
  

  // Blue Load LED Cathode Current Per Pulse vs Integrated Q
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Cathode Current per LED Pulse vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current/Pulse [Amperes/Pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Cathode Current Per Pulse vs Integrated Q, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Cathode Current per LED Pulse vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current/Pulse [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Gain vs Integrated Q
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_load_anode/blue_load_cathode_current_per_pulse)";
  plot.yBranch_err = "( (blue_load_anode/blue_load_cathode_current_per_pulse)*sqrt( pow(blue_load_anode_err/blue_load_anode, 2) + pow(blue_load_cathode_current_per_pulse_err/blue_load_cathode_current_per_pulse, 2) ) )";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Gain vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Gain [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Gain vs Integrated Q, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_load_anode/blue_load_cathode_current_per_pulse)";
  plot.yBranch_err = "( (blue_load_anode/blue_load_cathode_current_per_pulse)*sqrt( pow(blue_load_anode_err/blue_load_anode, 2) + pow(blue_load_cathode_current_per_pulse_err/blue_load_cathode_current_per_pulse, 2) ) )";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue Load LED, VPT Gain vs Integrated Charge";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Gain [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED VPT/PIN vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_anode";
  plot.yBranch_err = "blue_load_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Anode Response vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED VPT/PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_anode";
  plot.yBranch_err = "blue_load_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Anode Response vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();
  

  // Blue Load LED Anode vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_anode_raw";
  plot.yBranch_err = "blue_load_anode_raw_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, Uncorrected VPT Anode Response vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Anode Response, Uncorrected [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();
  

  // Blue Load LED Anode vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_anode_raw";
  plot.yBranch_err = "blue_load_anode_raw_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, Uncorrected VPT Anode Response vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Anode Response, Uncorrected [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();

  
  // Blue Load LED Cathode Current vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current";
  plot.yBranch_err = "blue_load_cathode_current_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Cathode Current vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current [Amperes/100ms Aperature]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Cathode Current vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current";
  plot.yBranch_err = "blue_load_cathode_current_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Cathode Current vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();
  

  // Blue Load LED Cathode Current Per Pulse vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Cathode Current per LED Pulse vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current/Pulse [Amperes/Pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Cathode Current Per Pulse vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Cathode Current per LED Pulse vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Cathode Current/Pulse [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Gain vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_load_anode/blue_load_cathode_current_per_pulse)";
  plot.yBranch_err = "( (blue_load_anode/blue_load_cathode_current_per_pulse)*sqrt( pow(blue_load_anode_err/blue_load_anode, 2) + pow(blue_load_cathode_current_per_pulse_err/blue_load_cathode_current_per_pulse, 2) ) )";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Gain vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Gain [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue Load LED Gain vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_load_anode/blue_load_cathode_current_per_pulse)";
  plot.yBranch_err = "( (blue_load_anode/blue_load_cathode_current_per_pulse)*sqrt( pow(blue_load_anode_err/blue_load_anode, 2) + pow(blue_load_cathode_current_per_pulse_err/blue_load_cathode_current_per_pulse, 2) ) )";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, VPT Gain vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "Gain [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Load LED PIN vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_pin";
  plot.yBranch_err = "blue_load_pin_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, PIN Response vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "PIN Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();
  
  
  // Blue Load LED PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_load_anode";
  plot.yBranch_err = "blue_load_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue Load LED, PIN Response vs Time";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "PIN Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  //plotList.push_back(plot);
  plot.reset();
  

  // Blue vs Orange Reference LED VPT/PIN
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "orange_reference_anode";
  plot.xBranch_err = "orange_reference_anode_err";
  plot.title       = "Blue vs Orange Reference Illumination";
  plot.yAxisTitle  = "Blue LED VPT Anode Response [Coulombs/Pulse]";
  plot.xAxisTitle  = "Orange LED VPT Anode Response [Coulombs/Pulse]";
  
  plotList.push_back(plot);
  plot.reset();


  // Blue vs Orange Reference LED VPT/PIN, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "orange_reference_anode";
  plot.xBranch_err = "orange_reference_anode_err";
  plot.title       = "Blue vs Orange Reference Illumination";
  plot.yAxisTitle  = "Blue LED VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Orange LED VPT Anode Response [Unitless]";
  plot.set_Normalize();
  
  plotList.push_back(plot);
  plot.reset();
  

      
  // Blue/Orange Reference LED VPT/PIN vs Integrated Q
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_reference_anode/orange_reference_anode)";
  plot.yBranch_err = "( (blue_reference_anode/orange_reference_anode)*sqrt( pow(blue_reference_anode_raw_err/blue_reference_anode_raw, 2) + pow(orange_reference_anode_raw_err/orange_reference_anode_raw, 2) ) )";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue/Orange Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue/Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue/Orange Reference LED VPT/PIN vs Integrated Q, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_reference_anode/orange_reference_anode)";
  plot.yBranch_err = "( (blue_reference_anode/orange_reference_anode)*sqrt( pow(blue_reference_anode_raw_err/blue_reference_anode_raw, 2) + pow(orange_reference_anode_raw_err/orange_reference_anode_raw, 2) ) )";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Blue/Orange Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Blue/Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();

  // Orange Reference LED VPT/PIN vs Integrated Q
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  //plot.title       = "Orange Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Orange Reference LED VPT/PIN vs Integrated Q, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference LED, VPT Anode Response vs Integrated Charge";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();

	
  // Blue/Orange Reference LED VPT/PIN vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_reference_anode/orange_reference_anode)";
  plot.yBranch_err = "( (blue_reference_anode/orange_reference_anode)*sqrt( pow(blue_reference_anode_raw_err/blue_reference_anode_raw, 2) + pow(orange_reference_anode_raw_err/orange_reference_anode_raw, 2) ) )";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue/Orange Reference LED, VPT Anode Response vs Time";
  plot.title       = "Blue/Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Blue/Orange Reference LED VPT/PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "(blue_reference_anode/orange_reference_anode)";
  plot.yBranch_err = "( (blue_reference_anode/orange_reference_anode)*sqrt( pow(blue_reference_anode_raw_err/blue_reference_anode_raw, 2) + pow(orange_reference_anode_raw_err/orange_reference_anode_raw, 2) ) )";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Blue/Orange Reference LED, VPT Anode Response vs Time";
  plot.title       = "Blue/Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();


  // Orange Reference LED VPT/PIN vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Orange Reference LED, VPT Anode Response vs Time";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();


  // Orange Reference LED VPT/PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Orange Reference LED, VPT Anode Response vs Time";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();
  
  
  // Orange Reference LED Anode vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_anode_raw";
  plot.yBranch_err = "orange_reference_anode_raw_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Orange Reference LED, Uncorrected VPT Anode Response vs Time";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response, Uncorrected [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();

  
  // Orange Reference LED Anode vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_anode_raw";
  plot.yBranch_err = "orange_reference_anode_raw_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Orange Reference LED, Uncorrected VPT Anode Response vs Time";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response, Uncorrected [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();
  

  // Orange Reference LED PIN vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_pin";
  plot.yBranch_err = "orange_reference_pin_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Orange Reference LED, PIN Response vs Time";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "PIN Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  
  //plotList.push_back(plot);
  plot.reset();
  
  
  // Orange Reference LED PIN vs Time, normalized to start of run
  plot.whichVpt    = "";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  //plot.title       = "Orange Reference LED, PIN Response vs Time";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "PIN Response [Unitless]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";
  plot.set_Normalize();

  plotList.push_back(plot);
  plot.reset();
  
  
  // Temperature vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "temperature";
  plot.yBranch_err = "temperature_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  plot.title       = "Temperature in Bore of Magnet";
  plot.yAxisTitle  = "Temperature [Celcius]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";

  plotList.push_back(plot);
  plot.reset();

  
  // Humidity vs Time
  plot.whichVpt    = "";
  plot.yBranch     = "humidity";
  plot.yBranch_err = "humidity_err";
  plot.xBranch     = "elapsed_time";
  plot.xBranch_err = "";
  plot.title       = "Humidity in Bore of Magnet";
  plot.yAxisTitle  = "Humidity [RH%]";
  plot.xAxisTitle  = "Elapsed Time [Hours]";

  plotList.push_back(plot);
  plot.reset();


  
  

  //
  // Draw all plots
  //
  analyzer.get_plots(plotList);


  
  return 0;
}
