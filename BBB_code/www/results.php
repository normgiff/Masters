<html>
  <head>
    <style>
      table {
        border-collapse: collapse;
      }
      table, td, th {
        border: 1px solid black;
      }
    </style>
  </head>
  <body>
    <?php

       $chip_name = $_POST['chip_name'];
       $cycle_len1 = $_POST['cycle_len1'];
       $lead_del1 = $_POST['lead_del1'];
       $lead_del2 = $_POST['lead_del2'];
       $trail_del1 = $_POST['trail_del1'];
       $cust_high = $_POST['cust_high'];
       $cust_low = $_POST['cust_low'];

       $schmoo_vdd = $_POST['schmoo_vdd'];
       $schmoo_vdd_high = $_POST['schmoo_vdd_high'];
       $schmoo_vdd_low = $_POST['schmoo_vdd_low'];
       $schmoo_vdd_step = $_POST['schmoo_vdd_step'];
       $schmoo_vdd_gnd = $_POST['schmoo_vdd_gnd'];

       $schmoo_gnd = $_POST['schmoo_gnd'];
       $schmoo_gnd_high = $_POST['schmoo_gnd_high'];
       $schmoo_gnd_low = $_POST['schmoo_gnd_low'];
       $schmoo_gnd_step = $_POST['schmoo_gnd_step'];
       $schmoo_gnd_vdd = $_POST['schmoo_gnd_vdd'];

       $signals_1 = json_encode($_POST['signals1']);
       $sig_loc_1 = json_encode($_POST['sig_loc1']);
       $ff_1 = json_encode($_POST['ff1']);
       $IO_1 = json_encode($_POST['IO1']);
       $test_cycle_1 = json_encode($_POST['test_cycle1']);

       $signals_2 = json_encode($_POST['signals2']);
       $sig_loc_2 = json_encode($_POST['sig_loc2']);
       $ff_2 = json_encode($_POST['ff2]']);
       $IO_2 = json_encode($_POST['IO2']);
       $test_cycle_2 = json_encode($_POST['test_cycle2']);

       $signals_3 = json_encode($_POST['signals3']);
       $sig_loc_3 = json_encode($_POST['sig_loc3']);
       $ff_3 = json_encode($_POST['ff3']);
       $IO_3 = json_encode($_POST['IO3']);
       $test_cycle_3 = json_encode($_POST['test_cycle3']);

       $signals_4 = json_encode($_POST['signals4']);
       $sig_loc_4 = json_encode($_POST['sig_loc4']);
       $ff_4 = json_encode($_POST['ff4']);
       $IO_4 = json_encode($_POST['IO4']);
       $test_cycle_4 = json_encode($_POST['test_cycle4']);

       $output = array();
       $rv = 0;
       $temp1_sig_num = count($_POST['signals1']);
       $temp2_sig_num = count($_POST['signals2']);
       $temp3_sig_num = count($_POST['signals3']);
       $temp4_sig_num = count($_POST['signals4']);
       
       echo("<u>DUT Information</u><br>");
       echo("<b>Chip name</b>: $chip_name<br>");       
       echo("<br>");

       $cycle_len = 10*$cycle_len1;
       $ledge_1 = 10*$lead_del1;
       $ledge_2 = 10*$lead_del2;
       $tedge = 10*$trail_del1;

       echo("<u>Test Cycle Configuration</u><br>");
       echo("<b>Cycle length</b>: $cycle_len ns<br>");
       echo("<b>Leading edge 1 (delay 1)</b>: $ledge_1 ns<br>");
       echo("<b>Leading edge 2 (delay 2)</b>: $ledge_2 ns<br>");
       echo("<b>Trailing edge (width)</b>: $tedge ns<br>");
       echo("<br>");

       echo("<u>Voltage Configuration</u><br>");
       echo("<b>High voltage</b>: $cust_high V<br>");
       echo("<b>Low voltage</b>: $cust_low V<br>"); 
       echo("<br>");

       echo("<u>Template Configuration</u><br>");
       if($_POST['signals1'][0] != "")
       {
	  echo("<br>");
          echo("<b>Template 1</b><br>");
          echo '
          <table>
	    <tr>
	      <td>Signal Name</td>
	      <td>Signal Location</td>
	      <td>Force Format</td>
	      <td>Pin Direction</td>
	      <td>Test Cycle</td>
	    </tr>';

          $index = 0;
	  $sig_loc = array_values($_POST['sig_loc1']);
	  $ff = array_values($_POST['ff1']);
	  $IO = array_values($_POST['IO1']);
	  $test_cycle = array_values($_POST['test_cycle1']);
	  
          foreach($_POST['signals1'] as $item)
          {
             echo "
	     <tr>
	       <td>$item</td>
	       <td>$sig_loc[$index]</td>
	       <td>$ff[$index]</td>
	       <td>$IO[$index]</td>
	       <td>$test_cycle[$index]</td>
	     </tr>";
	     $index++;
          }
	  echo '
             </table>';
       }
       else
       {
	  echo("<br>");
          echo("<b>Template 1</b> contains no signals.<br>");
	  $temp1_sig_num = 0;
       }

       if($_POST['signals2'][0] != "")
       {
	  echo("<br>");
          echo("<b>Template 2</b><br>");
          echo '
          <table>
	    <tr>
	      <td>Signal Name</td>
	      <td>Signal Location</td>
	      <td>Force Format</td>
	      <td>Pin Direction</td>
	      <td>Test Cycle</td>
	    </tr>';

          $index = 0;
	  $sig_loc = array_values($_POST['sig_loc2']);
	  $ff = array_values($_POST['ff2']);
	  $IO = array_values($_POST['IO2']);
	  $test_cycle = array_values($_POST['test_cycle2']);
	  
          foreach($_POST['signals2'] as $item)
          {
             echo "
	     <tr>
	       <td>$item</td>
	       <td>$sig_loc[$index]</td>
	       <td>$ff[$index]</td>
	       <td>$IO[$index]</td>
	       <td>$test_cycle[$index]</td>
	     </tr>";
	     $index++;
          }
	  echo '
             </table>';
       }
       else
       {
	  echo("<br>");
          echo("<b>Template 2</b> contains no signals.<br>");
	  $temp2_sig_num = 0;
       }

       if($_POST['signals3'][0] != "")
       {
	  echo("<br>");
          echo("<b>Template 3</b><br>");
          echo '
          <table>
	    <tr>
	      <td>Signal Name</td>
	      <td>Signal Location</td>
	      <td>Force Format</td>
	      <td>Pin Direction</td>
	      <td>Test Cycle</td>
	    </tr>';

          $index = 0;
	  $sig_loc = array_values($_POST['sig_loc3']);
	  $ff = array_values($_POST['ff3']);
	  $IO = array_values($_POST['IO3']);
	  $test_cycle = array_values($_POST['test_cycle3']);
	  
          foreach($_POST['signals3'] as $item)
          {
             echo "
	     <tr>
	       <td>$item</td>
	       <td>$sig_loc[$index]</td>
	       <td>$ff[$index]</td>
	       <td>$IO[$index]</td>
	       <td>$test_cycle[$index]</td>
	     </tr>";
	     $index++;
          }
	  echo '
             </table>';
       }
       else {
	  echo("<br>");
          echo("<b>Template 3</b> contains no signals.<br>");
	  $temp3_sig_num = 0;
       }

       if($_POST['signals4'][0] != "")
       {
	  echo("<br>");
          echo("<b>Template 4</b><br>");
          echo '
          <table>
	    <tr>
	      <td>Signal Name</td>
	      <td>Signal Location</td>
	      <td>Force Format</td>
	      <td>Pin Direction</td>
	      <td>Test Cycle</td>
	    </tr>';

          $index = 0;
	  $sig_loc = array_values($_POST['sig_loc4']);
	  $ff = array_values($_POST['ff4']);
	  $IO = array_values($_POST['IO4']);
	  $test_cycle = array_values($_POST['test_cycle4']);
	  
          foreach($_POST['signals4'] as $item)
          {
             echo "
	     <tr>
	       <td>$item</td>
	       <td>$sig_loc[$index]</td>
	       <td>$ff[$index]</td>
	       <td>$IO[$index]</td>
	       <td>$test_cycle[$index]</td>
	     </tr>";
	     $index++;
          }
	  echo '
             </table>';
       }
       else
       {
	  echo("<br>");
          echo("<b>Template 4</b> contains no signals.<br>");
	  $temp4_sig_num = 0;
       }

       exec("./a.out {$temp1_sig_num} {$signals_1} {$sig_loc_1} {$ff_1} {$IO_1} {$test_cycle_1} {$temp2_sig_num} {$signals_2} {$sig_loc_2} {$ff_2} {$IO_2} {$test_cycle_2} {$temp3_sig_num} {$signals_3} {$sig_loc_3} {$ff_3} {$IO_3} {$test_cycle_3} {$temp4_sig_num} {$signals_4} {$sig_loc_4} {$ff_4} {$IO_4} {$test_cycle_4}", $output, $rv);

       if($rv != 0)
       {
          die("ERROR: Return value $rv.<br>");
       }

       foreach($output as $line) 
       {
          echo("<p>$line</p><br>");
       }

      ?>
  </body>
</html>
