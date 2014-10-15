#!/bin/csh

echo '\n'
echo 'Making html pages for vpt directory'

set basedir = 'http://cern.ch/jgwood/plots/vpt_conditioning_analysis/'

set outputfile = '../plots/vpt_conditioning_analysis.html'

echo '<html>\n<body>\n\n\n\n\n' >! $outputfile 
echo '<h1> U.Va. and Brunel VPT Conditioning Analysis \n<br/>\n' >> $outputfile
echo '  Double Exponential Fits and General Plots \n<br/>\n' >> $outputfile
echo '\n' >> $outputfile

echo '<br/>\n<br/>\n' >> $outputfile
echo '<a href="http://cern.ch/jgwood/pages/main_index.html" text-align="left">Home</a><br/><br/>\n\n' >> $outputfile

echo '<a name="top"> Table of Contents </a></br>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#uva_all_good_runs"> plots for UVa, Best Runs </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#uva_run6"> plots for UVa, Run6 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#uva_run5"> plots for UVa, Run5 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#uva_run4"> plots for UVa, Run4 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#uva_run3"> plots for UVa, Run3 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#uva_run2"> plots for UVa, Run2 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#uva_run1"> plots for UVa, Run1 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#brunel_run2"> plots for Brunel, Run2 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#brunel_run1"> plots for Brunel, Run1 </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#summary"> Summary Plots </a><br/>\n' >> $outputfile

echo '<br/><br/><br/>\n' >> $outputfile


# Loop over each run
foreach x( uva_all_good_runs uva_run6 uva_run5 uva_run4 uva_run3 uva_run2 uva_run1 brunel_run2 brunel_run1 )

    echo '<h2> '$x' </h2>\n\n\n' >> $outputfile
    echo '<a name="'$x'"> </a><br/>\n' >> $outputfile
    echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#top"> Table of Contents </a><br/>\n' >> $outputfile

    
    # set up Table for plots
    echo '<table border="1">\n'       >> $outputfile
    echo '<tr>Plots for '$x' </tr>\n' >> $outputfile
    echo '<tr>\n'                     >> $outputfile
    echo '<td> Which Plot </td>\n'    >> $outputfile
    echo '<td> Image Link </td>\n'    >> $outputfile
      

  # Loop over each plot
  foreach y( _Fit_ _Overlay_ )  


    # loop over all files of this type
    foreach z(`/bin/ls -t ../plots/$x$y*.png`)

      set name = `echo $z:t:r | sed "s/_/\ /g"`
      echo $z
      echo $name

      echo '<tr><td align="center">'$name'\n</td>\n\n' >> $outputfile
     
      echo '<td>\n' >> $outputfile 
      echo '<a href = "'$basedir$z:t:r'.png"> \n' >> $outputfile
      echo '<img src= "'$basedir$z:t:r'.png" alt="plotsYo" width="1000px" height="600px" align="center" style="display:block"/></a></td>\n' >> $outputfile
      echo '</tr>\n\n' >> $outputfile   

    end

  end

  echo '</table>\n\n' >> $outputfile
  echo '<br/>\n<br/>\n' >> $outputfile

end


# set up Header for plots
echo '<h2> Summary </h2>\n\n\n' >> $outputfile
echo '<a name="summary"> </a><br/>\n' >> $outputfile
echo '<a href="http://jgwood.web.cern.ch/jgwood/pages/vpt_conditioning_analysis.html#top"> Table of Contents </a><br/>\n' >> $outputfile

# set up Table for plots
echo '<table border="1">\n'       >> $outputfile
echo '<tr>Summary Plots</tr>\n' >> $outputfile
echo '<tr>\n'                     >> $outputfile
echo '<td> Which Plot </td>\n'    >> $outputfile
echo '<td> Image Link </td>\n'    >> $outputfile
      
# Loop over plots
foreach x(`/bin/ls ../plots/h_fit*.png` )

  set name = `echo $x:t:r | sed "s/h_//" | sed "s/_/\ /g"`
  echo $x
  echo $name

  echo '<tr><td align="center">'$name'\n</td>\n\n' >> $outputfile
    
  echo '<td>\n' >> $outputfile 
  echo '<a href = "'$basedir$x:t:r'.png"> \n' >> $outputfile
  echo '<img src= "'$basedir$x:t:r'.png" alt="plotsYo" width="1000px" height="600px" align="center" style="display:block"/></a></td>\n' >> $outputfile
  echo '</tr>\n\n' >> $outputfile   

end

echo '</table>\n\n' >> $outputfile
echo '<br/>\n<br/>\n' >> $outputfile


# End of Page Info
echo '<a href="http://cern.ch/jgwood/pages/main_index.html" text-align="left">Home</a>\n\n' >> $outputfile
echo '<br/>\n<br/>\n' >> $outputfile
echo '<div id="footer">\n' >> $outputfile
echo 'John Wood - jgw2kb@virginia.edu - University of Virginia\n' >> $outputfile
echo '</body> \n </html> \n' >> $outputfile

	   
