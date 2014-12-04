// John Wood
// UVa HEP
// VPT Test Rig
//
// Fitting Macro
// vpt_fits.C

#include <vector>

#include "../interface/vpt_analysis.h"

int vpt_fits(){

  // Declare analysis object
  vpt_analysis analyzer(analysis_type::fit);
  
  //
  // Declare plots
  //
  plotInfo plot;
  vector<plotInfo> plotList;


  //
  // Brunel, Run1, vpt947, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double brunel_run1_vpt947_intQ = 0.00973;

  plot.whichVpt    = "brunel_run1_vpt947";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "(integrated_charge>0.0094)";

  plot.set_Averaging(10);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.00941, brunel_run1_vpt947_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();



  //
  // U.Va., Run1, vpt2182, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run1_vpt2182_intQ = 0.132;

  plot.whichVpt    = "uva_run1_vpt2182";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(10);

  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run1_vpt2182_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -100000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -10000.0, 0.0);
  plot.set_Param_Constraint(1, 0.0, 0.1);  // amplitudes must be +
  plot.set_Param_Constraint(3, 0.0, 0.1);

  //plotList.push_back(plot);
  plot.reset();


  
  //
  // U.Va., Run1, vpt2183, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run1_vpt2183_intQ = 0.0475;

  plot.whichVpt    = "uva_run1_vpt2183";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(10);

  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run1_vpt2183_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -100000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -10000.0, 0.0);
  
  //plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run1, vpt2184, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run1_vpt2184_intQ = 0.0405;

  plot.whichVpt    = "uva_run1_vpt2184";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(10);

  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run1_vpt2184_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -75000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -7500.0, 0.0);
  
  //plotList.push_back(plot);
  plot.reset();
  
  

  //
  // U.Va., Run1, vpt2185, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run1_vpt2185_intQ = 0.0515;

  plot.whichVpt    = "uva_run1_vpt2185";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(10);

  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run1_vpt2185_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);
  plot.set_Param_Constraint(1, 0.0, 1);  // amplitudes must be +
  plot.set_Param_Constraint(3, 0.0, 1);

  //plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run2, vpt7095, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run2_vpt7095_intQ = 0.0335;

  plot.whichVpt    = "uva_run2_vpt7095";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run2_vpt7095_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run2, vpt7112, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run2_vpt7112_intQ = 0.031;

  plot.whichVpt    = "uva_run2_vpt7112";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.set_Averaging(5);
        
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run2_vpt7112_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -50000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -5000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run2, vpt7120, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run2_vpt7120_intQ = 0.01805;

  plot.whichVpt    = "uva_run2_vpt7120";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run2_vpt7120_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

 

  //
  // U.Va., Run2, vpt7099, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run2_vpt7099_intQ = 0.027;

  plot.whichVpt    = "uva_run2_vpt7099";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run2_vpt7099_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);
  plot.set_Param_Constraint(1, 0.0, 0.1);  // amplitudes must be +
  plot.set_Param_Constraint(3, 0.0, 0.1);

  plotList.push_back(plot);
  plot.reset();
  
  

  //
  // U.Va., Run3, vpt12199, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run3_vpt12199_intQ = 0.0325;

  plot.whichVpt    = "uva_run3_vpt12199";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12199_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  


  //
  // U.Va., Run3, vpt12199, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run3_vpt12199_intQ = 0.0325;

  plot.whichVpt    = "uva_run3_vpt12199";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12199_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  //
  // U.Va., Run3, vpt12199, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run3_vpt12199_intQ = 0.0325;

  plot.whichVpt    = "uva_run3_vpt12199";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  //plot.extraCuts   = "integrated_charge>=0.0001 && (!(integrated_charge>=0.0045 && integrated_charge<=0.0065)) && (!(integrated_charge>=0.0015 && integrated_charge<=0.002))";
  plot.extraCuts   = "integrated_charge>=0.0001";

  //plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12199_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -80000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -8000.0, 0.0);
  
  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run3, vpt12920, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run3_vpt12920_intQ = 0.031;

  plot.whichVpt    = "uva_run3_vpt12920";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12920_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  

  //
  // U.Va., Run3, vpt12920, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run3_vpt12920_intQ = 0.0325;

  plot.whichVpt    = "uva_run3_vpt12920";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12920_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  

  //
  // U.Va., Run3, vpt12920, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run3_vpt12920_intQ = 0.031;

  plot.whichVpt    = "uva_run3_vpt12920";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  //plot.extraCuts   = "integrated_charge>=0.0001 && (!(integrated_charge>=0.0045 && integrated_charge<=0.0065)) && (!(integrated_charge>=0.0015 && integrated_charge<=0.002))";
  plot.extraCuts   = "integrated_charge>=0.0001";

  //plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12920_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -44500.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -4450.0, 0.0);
  
  plotList.push_back(plot);
  plot.reset();
  

  //
  // U.Va., Run3, vpt13041, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run3_vpt13041_intQ = 0.0348;

  plot.whichVpt    = "uva_run3_vpt13041";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt13041_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run3, vpt13041, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run3_vpt13041_intQ = 0.0348;

  plot.whichVpt    = "uva_run3_vpt13041";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt13041_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  

  //
  // U.Va., Run3, vpt13041, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run3_vpt13041_intQ = 0.0348;

  plot.whichVpt    = "uva_run3_vpt13041";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001 && (!(integrated_charge>=0.0045 && integrated_charge<=0.0065)) && (!(integrated_charge>=0.0015 && integrated_charge<=0.002))";
  //plot.extraCuts   = "integrated_charge>=0.0001";

  //plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt13041_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);
  
  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run3, vpt12797, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run3_vpt12797_intQ = 0.027;

  plot.whichVpt    = "uva_run3_vpt12797";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12797_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  

  //
  // U.Va., Run3, vpt12797, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run3_vpt12797_intQ = 0.027;

  plot.whichVpt    = "uva_run3_vpt12797";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12797_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run3, vpt12797, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run3_vpt12797_intQ = 0.027;

  plot.whichVpt    = "uva_run3_vpt12797";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001 && (!(integrated_charge>=0.0035 && integrated_charge<=0.0065))";
      
  plot.set_Averaging(1);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt12797_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
    
  //
  // U.Va., Run3, vpt13047, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run3_vpt13047_intQ = 0.0328;

  plot.whichVpt    = "uva_run3_vpt13047";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt13047_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);
  plot.set_Param_Constraint(1, 0.0, 0.1);  // amplitudes must be +
  plot.set_Param_Constraint(3, 0.0, 0.1);

  plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run3, vpt13047, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run3_vpt13047_intQ = 0.0328;

  plot.whichVpt    = "uva_run3_vpt13047";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt13047_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -100000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -10000.0, 0.0);
  //plot.set_Param_Constraint(1, 0.0, 1);  // amplitudes must be +
  //plot.set_Param_Constraint(3, 0.0, 1);

  plotList.push_back(plot);
  plot.reset();
  

  //
  // U.Va., Run3, vpt13047, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run3_vpt13047_intQ = 0.0328;

  plot.whichVpt    = "uva_run3_vpt13047";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001 && (!(integrated_charge>=0.0005 && integrated_charge<=0.002))";
      
  //plot.set_Averaging(1);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run3_vpt13047_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  
  //
  // U.Va., Run4, vpt14649, Blue Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt14649_intQ = 0.0120;
  double uva_run4_vpt14649_intQ = 0.008;

  plot.whichVpt    = "uva_run4_vpt14649";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt14649_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run4, vpt14649, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt14649_intQ = 0.0120;
  //double uva_run4_vpt14649_intQ = 0.008;

  plot.whichVpt    = "uva_run4_vpt14649";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt14649_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -7500.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -750.0, 0.0);
  plot.set_Param_Constraint(1, 0.0, 0.1);  // amplitudes must be +
  plot.set_Param_Constraint(3, 0.0, 0.1);

  //plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run4, vpt13042, Blue Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13042_intQ = 0.0208;
  double uva_run4_vpt13042_intQ = 0.014;

  plot.whichVpt    = "uva_run4_vpt13042";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
   
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13042_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();
  
  
  
  //
  // U.Va., Run4, vpt13042, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13042_intQ = 0.0208;
  //double uva_run4_vpt13042_intQ = 0.014;

  plot.whichVpt    = "uva_run4_vpt13042";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
   
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13042_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();
  
  

  //
  // U.Va., Run4, vpt13473, Blue Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13473_intQ = 0.0208;
  double uva_run4_vpt13473_intQ = 0.015;

  plot.whichVpt    = "uva_run4_vpt13473";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
   
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13473_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -2500.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -250.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run4, vpt13473, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13473_intQ = 0.0208;
  //double uva_run4_vpt13473_intQ = 0.015;

  plot.whichVpt    = "uva_run4_vpt13473";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
   
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13473_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -7500.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -750.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run4, vpt13383, Blue Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13383_intQ = 0.0208;
  double uva_run4_vpt13383_intQ = 0.011;

  plot.whichVpt    = "uva_run4_vpt13383";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
     
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13383_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);
  plot.set_Param_Constraint(1, 0.0, 0.1);  // amplitudes must be +
  plot.set_Param_Constraint(3, 0.0, 0.1);

  //plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run4, vpt13383, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13383_intQ = 0.0208;
  //double uva_run4_vpt13383_intQ = 0.011;

  plot.whichVpt    = "uva_run4_vpt13383";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
     
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13383_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);
  plot.set_Param_Constraint(1, 0.0, 0.1);  // amplitudes must be +
  plot.set_Param_Constraint(3, 0.0, 0.1);

  //plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run4, vpt13048, Blue Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13048_intQ = 0.017;
  double uva_run4_vpt13048_intQ = 0.011;

  plot.whichVpt    = "uva_run4_vpt13048";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13048_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -1000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -100.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run4, vpt13048, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run4_vpt13048_intQ = 0.017;
  //double uva_run4_vpt13048_intQ = 0.011;

  plot.whichVpt    = "uva_run4_vpt13048";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.extraCuts   = "(elapsed_time<1500)";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run4_vpt13048_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -5000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -500.0, 0.0);

  //plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run5, vpt6714, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run5_vpt6714_intQ = 0.0265;

  plot.whichVpt    = "uva_run5_vpt6714";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt6714_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run5, vpt6714, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run5_vpt6714_intQ = 0.0265;

  plot.whichVpt    = "uva_run5_vpt6714";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt6714_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  //
  // U.Va., Run5, vpt6714, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run5_vpt6714_intQ = 0.0265;

  plot.whichVpt    = "uva_run5_vpt6714";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt6714_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -300000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -30000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run5, vpt6415, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run5_vpt6415_intQ = 0.0194;

  plot.whichVpt    = "uva_run5_vpt6415";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt6415_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  

  //
  // U.Va., Run5, vpt6415, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run5_vpt6415_intQ = 0.0194;

  plot.whichVpt    = "uva_run5_vpt6415";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt6415_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  

  //
  // U.Va., Run5, vpt6415, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run5_vpt6415_intQ = 0.0194;

  plot.whichVpt    = "uva_run5_vpt6415";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt6415_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -100000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -10000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  //
  // U.Va., Run5, vpt7603, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run5_vpt7603_intQ = 0.021;

  plot.whichVpt    = "uva_run5_vpt7603";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt7603_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run5, vpt7603, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run5_vpt7603_intQ = 0.021;

  plot.whichVpt    = "uva_run5_vpt7603";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt7603_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  //
  // U.Va., Run5, vpt7603, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run5_vpt7603_intQ = 0.021;

  plot.whichVpt    = "uva_run5_vpt7603";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt7603_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -200000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -20000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();


  
  //
  // U.Va., Run5, vpt7205, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run5_vpt7205_intQ = 0.0265;

  plot.whichVpt    = "uva_run5_vpt7205";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt7205_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -1000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -100.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run5, vpt7205, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run5_vpt7205_intQ = 0.0265;

  plot.whichVpt    = "uva_run5_vpt7205";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt7205_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run5, vpt7205, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run5_vpt7205_intQ = 0.0265;

  plot.whichVpt    = "uva_run5_vpt7205";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt7205_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -200000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -20000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run5, vpt8127, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run5_vpt8127_intQ = 0.01425;

  plot.whichVpt    = "uva_run5_vpt8127";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt8127_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run5, vpt8127, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run5_vpt8127_intQ = 0.01425;

  plot.whichVpt    = "uva_run5_vpt8127";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt8127_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
 
 
  //
  // U.Va., Run5, vpt8127, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run5_vpt8127_intQ = 0.01425;

  plot.whichVpt    = "uva_run5_vpt8127";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run5_vpt8127_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -200000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -20000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  //
  // U.Va., Run6, vpt5620, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run6_vpt5620_intQ = 0.0322;

  plot.whichVpt    = "uva_run6_vpt5620";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt5620_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -5000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -500.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run6, vpt5620, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run6_vpt5620_intQ = 0.0322;

  plot.whichVpt    = "uva_run6_vpt5620";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt5620_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -5000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -500.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  //
  // U.Va., Run6, vpt5620, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run6_vpt5620_intQ = 0.0322;

  plot.whichVpt    = "uva_run6_vpt5620";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt5620_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -500000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -50000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  //
  // U.Va., Run6, vpt8172, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run6_vpt8172_intQ = 0.0346;

  plot.whichVpt    = "uva_run6_vpt8172";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt8172_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();


  //
  // U.Va., Run6, vpt8172, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run6_vpt8172_intQ = 0.0346;

  plot.whichVpt    = "uva_run6_vpt8172";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt8172_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -20000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -2000.0, 0.0);
  //plot.set_Param_Constraint(1, 0.0, 1);  // amplitudes must be +
  //plot.set_Param_Constraint(3, 0.0, 1);

  plotList.push_back(plot);
  plot.reset();


  //
  // U.Va., Run6, vpt8172, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run6_vpt8172_intQ = 0.0346;

  plot.whichVpt    = "uva_run6_vpt8172";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0003";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt8172_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -500000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -50000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  

   
  //
  // U.Va., Run6, vpt8605, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run6_vpt8605_intQ = 0.0475;

  plot.whichVpt    = "uva_run6_vpt8605";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt8605_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run6, vpt8605, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run6_vpt8605_intQ = 0.0475;

  plot.whichVpt    = "uva_run6_vpt8605";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt8605_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -5000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -500.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  

  //
  // U.Va., Run6, vpt8605, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run6_vpt8605_intQ = 0.0475;

  plot.whichVpt    = "uva_run6_vpt8605";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(10);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt8605_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -500000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -50000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run6, vpt14765, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run6_vpt14765_intQ = 0.0351;

  plot.whichVpt    = "uva_run6_vpt14765";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt14765_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  

  //
  // U.Va., Run6, vpt14765, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run6_vpt14765_intQ = 0.0351;

  plot.whichVpt    = "uva_run6_vpt14765";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";

  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt14765_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -5000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -500.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

 

  //
  // U.Va., Run6, vpt14765, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run6_vpt14765_intQ = 0.0351;

  plot.whichVpt    = "uva_run6_vpt14765";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt14765_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -500000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -50000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run6, vpt14753, Blue Reference LED VPT/PIN vs Integrated Q
  //
  double uva_run6_vpt14753_intQ = 0.017;

  plot.whichVpt    = "uva_run6_vpt14753";
  plot.yBranch     = "blue_reference_anode";
  plot.yBranch_err = "blue_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt14753_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();

  
  
  //
  // U.Va., Run6, vpt14753, Orange Reference LED VPT/PIN vs Integrated Q
  //
  //double uva_run6_vpt14753_intQ = 0.017;

  plot.whichVpt    = "uva_run6_vpt14753";
  plot.yBranch     = "orange_reference_anode";
  plot.yBranch_err = "orange_reference_anode_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Orange Reference Illumination";
  plot.yAxisTitle  = "VPT Anode Response [Coulombs/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
      
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt14753_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -10000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -1000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
  
  //
  // U.Va., Run6, vpt14753, Blue Load Cathode Current Per Pulse vs Integrated Q
  //
  //double uva_run6_vpt14753_intQ = 0.017;

  plot.whichVpt    = "uva_run6_vpt14753";
  plot.yBranch     = "blue_load_cathode_current_per_pulse";
  plot.yBranch_err = "blue_load_cathode_current_per_pulse_err";
  plot.xBranch     = "integrated_charge";
  plot.xBranch_err = "integrated_charge_err";
  plot.title       = "Blue Load Illumination";
  plot.yAxisTitle  = "VPT Cathode Response [Amperes/pulse]";
  plot.xAxisTitle  = "Integrated Charge [Coulombs]";
  plot.extraCuts   = "integrated_charge>=0.0001";
  
  plot.set_Averaging(5);
      
  plot.set_Fit("Double Exponential", "[0]+[1]*exp(x/[2])+[3]*exp(x/[4])", 0.0, uva_run6_vpt14753_intQ);
  
  plot.set_Param_Name(0, "C");
  plot.set_Param_Name(1, "\\Alpha_{1}");
  plot.set_Param_Name(2, "\\tau_{1}");
  plot.set_Param_Name(3, "\\Alpha_{2}");
  plot.set_Param_Name(4, "\\tau_{2}");
  
  plot.set_Param_Constraint(2, -100000.0, 0.0);  // time constants must be -
  plot.set_Param_Constraint(4, -10000.0, 0.0);

  plotList.push_back(plot);
  plot.reset();
  
 
  

  //
  // Get Fits
  //
  analyzer.get_plots(plotList);
  analyzer.get_fit_result_plots();



  //
  // Get normalized plots for fits
  //
  for(int iPlot=0; iPlot<(int)plotList.size(); iPlot++){
    plotList[iPlot].set_Normalize();
  }
  analyzer.get_plots(plotList);



  return 0;
}
