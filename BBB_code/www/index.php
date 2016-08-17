<html>
  <head>
    <link rel="stylesheet" type="text/css" href="web_form.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js"></script>
    <script src="web_form.js"></script>
  </head>

  <body>
    <form action="results.php" method="post">
      <h2>LV600 Test Form</h2>

      <b>NOTE</b>: * denotes required field. Default values are provided for convenience.
      <br>
      <br>

      <b>DUT Information</b>
      <br>
      Chip name: <input type="text" name="chip_name" value="My Chip"> 
      <br>
      <br>

      <b>Test Cycle Configuration</b><br>
      Please enter a positive integer for the four fields below.<br>
      Inputted values are scaled by <b>10 ns</b>.<br>
      *Cycle Length: <input type="text" name="cycle_len1" value="20"><br>
      *Leading Edge 1: <input type="text" name="lead_del1" value="8"><br>
      *Leading Edge 2: <input type="text" name="lead_del2" value="10"><br>
      *Trailing Edge: <input type="text" name="trail_del1" value="14"><br>
      <br>

      <b>Logic Levels</b><br>
      For each logic level, please enter a number within the corresponding range.<br> 
      *Logic High (4V - 5V): <input type="text" name="cust_high" value="5"><br>
      *Logic Low (0V - 1V): <input type="text" name="cust_low" value="0"><br>
      <br>

      <b>Schmooing</b><br>
      *Schmoo VDD?
      <select name="schmoo_vdd">
	<option value="yes">Yes</option>
	<option value="no" selected>No</option>
      </select>
      Starting VDD: <input type="text" name="schmoo_vdd_high" value="5">
      Ending VDD: <input type="text" name="schmoo_vdd_low" value="4.2">
      Step by: <input type="text" name="scmoo_vdd_step" value="0.1">
      Fix GND at: <input type="text" name="scmoo_vdd_gnd" value="0"><br>
      <b>NOTE</b>: Starting VDD must be greater than Ending VDD.
      <br>

      *Schmoo GND?
      <select name="schmoo_gnd">
	<option value="yes">Yes</option>
	<option value="no" selected>No</option>
      </select>
      Starting GND: <input type="text" name="schmoo_gnd_low" value="0">
      Ending GND: <input type="text" name="schmoo_gnd_high" value="0.9">
      Step by: <input type="text" name="scmoo_gnd_step" value="0.1">
      Fix VDD at: <input type="text" name="scmoo_gnd_vdd" value="5"><br>
      <b>NOTE</b>: Starting GND must be less than Ending GND.
      <br>
      <br>

      <b>Signal and Template Configuration</b><br>
      <b>NOTE</b>: Leading Edge values are ignored for output signals.<br>
      <br>

      <u>Template 1</u>
      <br>
      <button id="add_sig_temp1" type="button">Append Signal to Template 1</button>
      <button id="remove_sig_temp1" type="button">Remove Signal from Template 1</button>
      <br>
      <ol id="signals1">
      </ol>

      <u>Template 2</u><br>
      <button id="add_sig_temp2" type="button">Append Signal to Template 2</button>
      <button id="remove_sig_temp2" type="button">Remove Signal from Template 2</button>
      <br>
      <ol id="signals2">
      </ol>

      <u>Template 3</u>
      <br>
      <button id="add_sig_temp3" type="button">Append Signal to Template 3</button>
      <button id="remove_sig_temp3" type="button">Remove Signal from Template 3</button>
      <br>
      <ol id="signals3">
      </ol>

      <u>Template 4</u>
      <br>
      <button id="add_sig_temp4" type="button">Append Signal to Template 4</button>
      <button id="remove_sig_temp4" type="button">Remove Signal from Template 4</button>
      <br>
      <ol id="signals4">
      </ol>
      <br>

      <b>Input and Output Vectors</b>
      <br>
      <b>NOTES</b>: 
      <ol>
	<li>Vectors must be specified using <b>binary</b>. Other radii are not supported at the moment.</li>
	<li>Bits must be <b>space-separated</b>.</li>
	<li>Input and output values are ordered by <b>top->down</b> order in the corresponding template above.</li>
      </ol>

      <button id="add_test_vector" type="button">Append Test Vector</button>
      <button id="remove_test_vector" type="button">Remove Test Vector</button>
      <br>

      <ol id="test_vectors">
	<li>Template:  
	  <select name="template_for_vector">
	    <option value="1" selected>1</option>
	    <option value="2">2</option>
	    <option value="3">3</option>
	    <option value="4">4</option>
	  </select>
	  <br>
	  Input Value Assignments: <input type="text" size="150" name="inputs[]"><br>
	  Expected Outputs Values: <input type="text" size="150" name="outputs[]"></li>
      </ol>

      <input type="submit">
    </form>
  </body>
</html>
