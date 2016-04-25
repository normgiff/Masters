<html>
<head>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js"></script>
<script>
$(document).ready(function(){
    $("#add_test_vector").click(function(){
        $("#test_vectors").append("<li >Test Vectors: <input type='text' size='150'"
        + "name='test[]'><br> Expected Result:  <input type='text' size='150' name='result[]'>"
        + "</li>");
    });
});

$(document).ready(function(){
    $("#remove_test_vector").click(function(){
        $("#test_vectors li:last-child").remove();
    });
});

$(document).ready(function(){
    $("#add_sig_temp1").click(function(){
        $("#signals1").append("<li>Signal Name: <input type='text' name='signals1[]'>"
        + " Signal Location: <select name='sig_loc1[]'>"
		+ "<option value='A1'>A1</option>"
		+ "<option value='A2'>A2</option>"
		+ "<option value='A3'>A3</option>"
		+ "<option value='A4'>A4</option>"
		+ "<option value='A5'>A5</option>"
		+ "<option value='A6'>A6</option>"
		+ "<option value='A7'>A7</option>"
		+ "<option value='A8'>A8</option>"
		+ "<option value='A9'>A9</option>"
		+ "<option value='A10'>A10</option>"
		+ "<option value='A11'>A11</option>"
		+ "<option value='A12'>A12</option>"
		+ "<option value='A13'>A13</option>"
		+ "<option value='B1'>B1</option>"
		+ "<option value='B2'>B2</option>"
		+ "<option value='B3'>B3</option>"
		+ "<option value='B4'>B4</option>"
		+ "<option value='B5'>B5</option>"
		+ "<option value='B6'>B6</option>"
		+ "<option value='B7'>B7</option>"
		+ "<option value='B8'>B8</option>"
		+ "<option value='B9'>B9</option>"
		+ "<option value='B10'>B10</option>"
		+ "<option value='B11'>B11</option>"
		+ "<option value='B12'>B12</option>"
		+ "<option value='B13'>B13</option>"
		+ "<option value='C1'>C1</option>"
		+ "<option value='C2'>C2</option>"
		+ "<option value='C3'>C3</option>"
		+ "<option value='C4'>C4</option>"
		+ "<option value='C5'>C5</option>"
		+ "<option value='C6'>C6</option>"
		+ "<option value='C7'>C7</option>"
		+ "<option value='C8'>C8</option>"
		+ "<option value='C9'>C9</option>"
		+ "<option value='C10'>C10</option>"
		+ "<option value='C11'>C11</option>"
		+ "<option value='C12'>C12</option>"
		+ "<option value='C13'>C13</option>"
		+ "<option value='D1'>D1</option>"
		+ "<option value='D2'>D2</option>"
		+ "<option value='D3'>D3</option>"
		+ "<option value='D4'>D4</option>"
		+ "<option value='D5'>D5</option>"
		+ "<option value='D6'>D6</option>"
		+ "<option value='D7'>D7</option>"
		+ "<option value='D8'>D8</option>"
		+ "<option value='D9'>D9</option>"
		+ "<option value='D10'>D10</option>"
		+ "<option value='D11'>D11</option>"
		+ "<option value='D12'>D12</option>"
		+ "<option value='D13'>D13</option>"
		+ "<option value='E1'>E1</option>"
		+ "<option value='E2'>E2</option>"
		+ "<option value='E3'>E3</option>"
		+ "<option value='E4'>E4</option>"
		+ "<option value='E5'>E5</option>"
		+ "<option value='E6'>E6</option>"
		+ "<option value='E7'>E7</option>"
		+ "<option value='E8'>E8</option>"
		+ "<option value='E9'>E9</option>"
		+ "<option value='E10'>E10</option>"
		+ "<option value='E11'>E11</option>"
		+ "<option value='E12'>E12</option>"
		+ "<option value='E13'>E13</option>"
		+ "<option value='F1'>F1</option>"
		+ "<option value='F2'>F2</option>"
		+ "<option value='F3'>F3</option>"
		+ "<option value='F4'>F4</option>"
		+ "<option value='F5'>F5</option>"
		+ "<option value='F6'>F6</option>"
		+ "<option value='F7'>F7</option>"
		+ "<option value='F8'>F8</option>"
		+ "<option value='F9'>F9</option>"
		+ "<option value='F10'>F10</option>"
		+ "<option value='F11'>F11</option>"
		+ "<option value='F12'>F12</option>"
		+ "<option value='F13'>F13</option>"
		+ "<option value='G1'>G1</option>"
		+ "<option value='G2'>G2</option>"
		+ "<option value='G3'>G3</option>"
		+ "<option value='G4'>G4</option>"
		+ "<option value='G5'>G5</option>"
		+ "<option value='G6'>G6</option>"
		+ "<option value='G7'>G7</option>"
		+ "<option value='G8'>G8</option>"
		+ "<option value='G9'>G9</option>"
		+ "<option value='G10'>G10</option>"
		+ "<option value='G11'>G11</option>"
		+ "<option value='G12'>G12</option>"
		+ "<option value='G13'>G13</option>"
		+ "<option value='H1'>H1</option>"
		+ "<option value='H2'>H2</option>"
		+ "<option value='H3'>H3</option>"
		+ "<option value='H4'>H4</option>"
		+ "<option value='H5'>H5</option>"
		+ "<option value='H6'>H6</option>"
		+ "<option value='H7'>H7</option>"
		+ "<option value='H8'>H8</option>"
		+ "<option value='H9'>H9</option>"
		+ "<option value='H10'>H10</option>"
		+ "<option value='H11'>H11</option>"
		+ "<option value='H12'>H12</option>"
		+ "<option value='H13'>H13</option>"
		+ "<option value='J1'>J1</option>"
		+ "<option value='J2'>J2</option>"
		+ "<option value='J3'>J3</option>"
		+ "<option value='J4'>J4</option>"
		+ "<option value='J5'>J5</option>"
		+ "<option value='J6'>J6</option>"
		+ "<option value='J7'>J7</option>"
		+ "<option value='J8'>J8</option>"
		+ "<option value='J9'>J9</option>"
		+ "<option value='J10'>J10</option>"
		+ "<option value='J11'>J11</option>"
		+ "<option value='J12'>J12</option>"
		+ "<option value='J13'>J13</option>"
		+ "<option value='K1'>K1</option>"
		+ "<option value='K2'>K2</option>"
		+ "<option value='K3'>K3</option>"
		+ "<option value='K4'>K4</option>"
		+ "<option value='K5'>K5</option>"
		+ "<option value='K6'>K6</option>"
		+ "<option value='K7'>K7</option>"
		+ "<option value='K8'>K8</option>"
		+ "<option value='K9'>K9</option>"
		+ "<option value='K10'>K10</option>"
		+ "<option value='K11'>K11</option>"
		+ "<option value='K12'>K12</option>"
		+ "<option value='K13'>K13</option>"
		+ "<option value='L1'>L1</option>"
		+ "<option value='L2'>L2</option>"
		+ "<option value='L3'>L3</option>"
		+ "<option value='L4'>L4</option>"
		+ "<option value='L5'>L5</option>"
		+ "<option value='L6'>L6</option>"
		+ "<option value='L7'>L7</option>"
		+ "<option value='L8'>L8</option>"
		+ "<option value='L9'>L9</option>"
		+ "<option value='L10'>L10</option>"
		+ "<option value='L11'>L11</option>"
		+ "<option value='L12'>L12</option>"
		+ "<option value='L13'>L13</option>"
		+ "<option value='M1'>M1</option>"
		+ "<option value='M2'>M2</option>"
		+ "<option value='M3'>M3</option>"
		+ "<option value='M4'>M4</option>"
		+ "<option value='M5'>M5</option>"
		+ "<option value='M6'>M6</option>"
		+ "<option value='M7'>M7</option>"
		+ "<option value='M8'>M8</option>"
		+ "<option value='M9'>M9</option>"
		+ "<option value='M10'>M10</option>"
		+ "<option value='M11'>M11</option>"
		+ "<option value='M12'>M12</option>"
		+ "<option value='M13'>M13</option>"
		+ "<option value='N1'>N1</option>"
		+ "<option value='N2'>N2</option>"
		+ "<option value='N3'>N3</option>"
		+ "<option value='N4'>N4</option>"
		+ "<option value='N5'>N5</option>"
		+ "<option value='N6'>N6</option>"
		+ "<option value='N7'>N7</option>"
		+ "<option value='N8'>N8</option>"
		+ "<option value='N9'>N9</option>"
		+ "<option value='N10'>N10</option>"
		+ "<option value='N11'>N11</option>"
		+ "<option value='N12'>N12</option>"
		+ "<option value='N13'>N13</option>"
		+ "</select>"
		+ " Force Format: <select name=,ff1[],>"
  		+ "	<option value='r_0'>R0</option>"
  		+ "	<option value='dnr_l'>DNRZ_L</option>"
		+ "</select>"
		+ " I/O: <select name='IO1[]'>"
  		+ "	<option value='input'>Input</option>"
  		+ "	<option value='output'>Output</option>"
  		+ "</select> "
  		+ " Test Cycle: <select name='test_cycle1[]'>"
  		+ "	<option value='test1'>1</option>"
  		+ "	<option value='test2'>2</option>"
  		+ "</select> "
  		+ "<br>"
		+"</li>");
    });
});

$(document).ready(function(){
    $("#remove_sig_temp1").click(function(){
        $("#signals1 li:last-child").remove();
    });
});

$(document).ready(function(){
    $("#add_sig_temp2").click(function(){
        $("#signals2").append("<li>Signal Name: <input type='text' name='signals2[]'>"
		+ " Signal Location: <select name='sig_loc2[]'>"
		+ "<option value='A1'>A1</option>"
		+ "<option value='A2'>A2</option>"
		+ "<option value='A3'>A3</option>"
		+ "<option value='A4'>A4</option>"
		+ "<option value='A5'>A5</option>"
		+ "<option value='A6'>A6</option>"
		+ "<option value='A7'>A7</option>"
		+ "<option value='A8'>A8</option>"
		+ "<option value='A9'>A9</option>"
		+ "<option value='A10'>A10</option>"
		+ "<option value='A11'>A11</option>"
		+ "<option value='A12'>A12</option>"
		+ "<option value='A13'>A13</option>"
		+ "<option value='B1'>B1</option>"
		+ "<option value='B2'>B2</option>"
		+ "<option value='B3'>B3</option>"
		+ "<option value='B4'>B4</option>"
		+ "<option value='B5'>B5</option>"
		+ "<option value='B6'>B6</option>"
		+ "<option value='B7'>B7</option>"
		+ "<option value='B8'>B8</option>"
		+ "<option value='B9'>B9</option>"
		+ "<option value='B10'>B10</option>"
		+ "<option value='B11'>B11</option>"
		+ "<option value='B12'>B12</option>"
		+ "<option value='B13'>B13</option>"
		+ "<option value='C1'>C1</option>"
		+ "<option value='C2'>C2</option>"
		+ "<option value='C3'>C3</option>"
		+ "<option value='C4'>C4</option>"
		+ "<option value='C5'>C5</option>"
		+ "<option value='C6'>C6</option>"
		+ "<option value='C7'>C7</option>"
		+ "<option value='C8'>C8</option>"
		+ "<option value='C9'>C9</option>"
		+ "<option value='C10'>C10</option>"
		+ "<option value='C11'>C11</option>"
		+ "<option value='C12'>C12</option>"
		+ "<option value='C13'>C13</option>"
		+ "<option value='D1'>D1</option>"
		+ "<option value='D2'>D2</option>"
		+ "<option value='D3'>D3</option>"
		+ "<option value='D4'>D4</option>"
		+ "<option value='D5'>D5</option>"
		+ "<option value='D6'>D6</option>"
		+ "<option value='D7'>D7</option>"
		+ "<option value='D8'>D8</option>"
		+ "<option value='D9'>D9</option>"
		+ "<option value='D10'>D10</option>"
		+ "<option value='D11'>D11</option>"
		+ "<option value='D12'>D12</option>"
		+ "<option value='D13'>D13</option>"
		+ "<option value='E1'>E1</option>"
		+ "<option value='E2'>E2</option>"
		+ "<option value='E3'>E3</option>"
		+ "<option value='E4'>E4</option>"
		+ "<option value='E5'>E5</option>"
		+ "<option value='E6'>E6</option>"
		+ "<option value='E7'>E7</option>"
		+ "<option value='E8'>E8</option>"
		+ "<option value='E9'>E9</option>"
		+ "<option value='E10'>E10</option>"
		+ "<option value='E11'>E11</option>"
		+ "<option value='E12'>E12</option>"
		+ "<option value='E13'>E13</option>"
		+ "<option value='F1'>F1</option>"
		+ "<option value='F2'>F2</option>"
		+ "<option value='F3'>F3</option>"
		+ "<option value='F4'>F4</option>"
		+ "<option value='F5'>F5</option>"
		+ "<option value='F6'>F6</option>"
		+ "<option value='F7'>F7</option>"
		+ "<option value='F8'>F8</option>"
		+ "<option value='F9'>F9</option>"
		+ "<option value='F10'>F10</option>"
		+ "<option value='F11'>F11</option>"
		+ "<option value='F12'>F12</option>"
		+ "<option value='F13'>F13</option>"
		+ "<option value='G1'>G1</option>"
		+ "<option value='G2'>G2</option>"
		+ "<option value='G3'>G3</option>"
		+ "<option value='G4'>G4</option>"
		+ "<option value='G5'>G5</option>"
		+ "<option value='G6'>G6</option>"
		+ "<option value='G7'>G7</option>"
		+ "<option value='G8'>G8</option>"
		+ "<option value='G9'>G9</option>"
		+ "<option value='G10'>G10</option>"
		+ "<option value='G11'>G11</option>"
		+ "<option value='G12'>G12</option>"
		+ "<option value='G13'>G13</option>"
		+ "<option value='H1'>H1</option>"
		+ "<option value='H2'>H2</option>"
		+ "<option value='H3'>H3</option>"
		+ "<option value='H4'>H4</option>"
		+ "<option value='H5'>H5</option>"
		+ "<option value='H6'>H6</option>"
		+ "<option value='H7'>H7</option>"
		+ "<option value='H8'>H8</option>"
		+ "<option value='H9'>H9</option>"
		+ "<option value='H10'>H10</option>"
		+ "<option value='H11'>H11</option>"
		+ "<option value='H12'>H12</option>"
		+ "<option value='H13'>H13</option>"
		+ "<option value='J1'>J1</option>"
		+ "<option value='J2'>J2</option>"
		+ "<option value='J3'>J3</option>"
		+ "<option value='J4'>J4</option>"
		+ "<option value='J5'>J5</option>"
		+ "<option value='J6'>J6</option>"
		+ "<option value='J7'>J7</option>"
		+ "<option value='J8'>J8</option>"
		+ "<option value='J9'>J9</option>"
		+ "<option value='J10'>J10</option>"
		+ "<option value='J11'>J11</option>"
		+ "<option value='J12'>J12</option>"
		+ "<option value='J13'>J13</option>"
		+ "<option value='K1'>K1</option>"
		+ "<option value='K2'>K2</option>"
		+ "<option value='K3'>K3</option>"
		+ "<option value='K4'>K4</option>"
		+ "<option value='K5'>K5</option>"
		+ "<option value='K6'>K6</option>"
		+ "<option value='K7'>K7</option>"
		+ "<option value='K8'>K8</option>"
		+ "<option value='K9'>K9</option>"
		+ "<option value='K10'>K10</option>"
		+ "<option value='K11'>K11</option>"
		+ "<option value='K12'>K12</option>"
		+ "<option value='K13'>K13</option>"
		+ "<option value='L1'>L1</option>"
		+ "<option value='L2'>L2</option>"
		+ "<option value='L3'>L3</option>"
		+ "<option value='L4'>L4</option>"
		+ "<option value='L5'>L5</option>"
		+ "<option value='L6'>L6</option>"
		+ "<option value='L7'>L7</option>"
		+ "<option value='L8'>L8</option>"
		+ "<option value='L9'>L9</option>"
		+ "<option value='L10'>L10</option>"
		+ "<option value='L11'>L11</option>"
		+ "<option value='L12'>L12</option>"
		+ "<option value='L13'>L13</option>"
		+ "<option value='M1'>M1</option>"
		+ "<option value='M2'>M2</option>"
		+ "<option value='M3'>M3</option>"
		+ "<option value='M4'>M4</option>"
		+ "<option value='M5'>M5</option>"
		+ "<option value='M6'>M6</option>"
		+ "<option value='M7'>M7</option>"
		+ "<option value='M8'>M8</option>"
		+ "<option value='M9'>M9</option>"
		+ "<option value='M10'>M10</option>"
		+ "<option value='M11'>M11</option>"
		+ "<option value='M12'>M12</option>"
		+ "<option value='M13'>M13</option>"
		+ "<option value='N1'>N1</option>"
		+ "<option value='N2'>N2</option>"
		+ "<option value='N3'>N3</option>"
		+ "<option value='N4'>N4</option>"
		+ "<option value='N5'>N5</option>"
		+ "<option value='N6'>N6</option>"
		+ "<option value='N7'>N7</option>"
		+ "<option value='N8'>N8</option>"
		+ "<option value='N9'>N9</option>"
		+ "<option value='N10'>N10</option>"
		+ "<option value='N11'>N11</option>"
		+ "<option value='N12'>N12</option>"
		+ "<option value='N13'>N13</option>"
		+ "</select>"
		+ " Force Format: <select name=,ff2[],>"
  		+ "	<option value='r_0'>R0</option>"
  		+ "	<option value='dnr_l'>DNRZ_L</option>"
		+ "</select>"
		+ " I/O: <select name='IO2[]'>"
  		+ "	<option value='input'>Input</option>"
  		+ "	<option value='output'>Output</option>"
  		+ "</select> "
  		+ " Test Cycle: <select name='test_cycle2[]'>"
  		+ "	<option value='test1'>1</option>"
  		+ "	<option value='test2'>2</option>"
  		+ "</select> "
  		+ "<br>"
		+"</li>");
    });
});

$(document).ready(function(){
    $("#remove_sig_temp2").click(function(){
        $("#signals2 li:last-child").remove();
    });
});


$(document).ready(function(){
    $("#add_sig_temp3").click(function(){
        $("#signals3").append("<li>Signal Name: <input type='text' name='signals3[]'>"
		+ " Signal Location: <select name='sig_loc3[]'>"
		+ "<option value='A1'>A1</option>"
		+ "<option value='A2'>A2</option>"
		+ "<option value='A3'>A3</option>"
		+ "<option value='A4'>A4</option>"
		+ "<option value='A5'>A5</option>"
		+ "<option value='A6'>A6</option>"
		+ "<option value='A7'>A7</option>"
		+ "<option value='A8'>A8</option>"
		+ "<option value='A9'>A9</option>"
		+ "<option value='A10'>A10</option>"
		+ "<option value='A11'>A11</option>"
		+ "<option value='A12'>A12</option>"
		+ "<option value='A13'>A13</option>"
		+ "<option value='B1'>B1</option>"
		+ "<option value='B2'>B2</option>"
		+ "<option value='B3'>B3</option>"
		+ "<option value='B4'>B4</option>"
		+ "<option value='B5'>B5</option>"
		+ "<option value='B6'>B6</option>"
		+ "<option value='B7'>B7</option>"
		+ "<option value='B8'>B8</option>"
		+ "<option value='B9'>B9</option>"
		+ "<option value='B10'>B10</option>"
		+ "<option value='B11'>B11</option>"
		+ "<option value='B12'>B12</option>"
		+ "<option value='B13'>B13</option>"
		+ "<option value='C1'>C1</option>"
		+ "<option value='C2'>C2</option>"
		+ "<option value='C3'>C3</option>"
		+ "<option value='C4'>C4</option>"
		+ "<option value='C5'>C5</option>"
		+ "<option value='C6'>C6</option>"
		+ "<option value='C7'>C7</option>"
		+ "<option value='C8'>C8</option>"
		+ "<option value='C9'>C9</option>"
		+ "<option value='C10'>C10</option>"
		+ "<option value='C11'>C11</option>"
		+ "<option value='C12'>C12</option>"
		+ "<option value='C13'>C13</option>"
		+ "<option value='D1'>D1</option>"
		+ "<option value='D2'>D2</option>"
		+ "<option value='D3'>D3</option>"
		+ "<option value='D4'>D4</option>"
		+ "<option value='D5'>D5</option>"
		+ "<option value='D6'>D6</option>"
		+ "<option value='D7'>D7</option>"
		+ "<option value='D8'>D8</option>"
		+ "<option value='D9'>D9</option>"
		+ "<option value='D10'>D10</option>"
		+ "<option value='D11'>D11</option>"
		+ "<option value='D12'>D12</option>"
		+ "<option value='D13'>D13</option>"
		+ "<option value='E1'>E1</option>"
		+ "<option value='E2'>E2</option>"
		+ "<option value='E3'>E3</option>"
		+ "<option value='E4'>E4</option>"
		+ "<option value='E5'>E5</option>"
		+ "<option value='E6'>E6</option>"
		+ "<option value='E7'>E7</option>"
		+ "<option value='E8'>E8</option>"
		+ "<option value='E9'>E9</option>"
		+ "<option value='E10'>E10</option>"
		+ "<option value='E11'>E11</option>"
		+ "<option value='E12'>E12</option>"
		+ "<option value='E13'>E13</option>"
		+ "<option value='F1'>F1</option>"
		+ "<option value='F2'>F2</option>"
		+ "<option value='F3'>F3</option>"
		+ "<option value='F4'>F4</option>"
		+ "<option value='F5'>F5</option>"
		+ "<option value='F6'>F6</option>"
		+ "<option value='F7'>F7</option>"
		+ "<option value='F8'>F8</option>"
		+ "<option value='F9'>F9</option>"
		+ "<option value='F10'>F10</option>"
		+ "<option value='F11'>F11</option>"
		+ "<option value='F12'>F12</option>"
		+ "<option value='F13'>F13</option>"
		+ "<option value='G1'>G1</option>"
		+ "<option value='G2'>G2</option>"
		+ "<option value='G3'>G3</option>"
		+ "<option value='G4'>G4</option>"
		+ "<option value='G5'>G5</option>"
		+ "<option value='G6'>G6</option>"
		+ "<option value='G7'>G7</option>"
		+ "<option value='G8'>G8</option>"
		+ "<option value='G9'>G9</option>"
		+ "<option value='G10'>G10</option>"
		+ "<option value='G11'>G11</option>"
		+ "<option value='G12'>G12</option>"
		+ "<option value='G13'>G13</option>"
		+ "<option value='H1'>H1</option>"
		+ "<option value='H2'>H2</option>"
		+ "<option value='H3'>H3</option>"
		+ "<option value='H4'>H4</option>"
		+ "<option value='H5'>H5</option>"
		+ "<option value='H6'>H6</option>"
		+ "<option value='H7'>H7</option>"
		+ "<option value='H8'>H8</option>"
		+ "<option value='H9'>H9</option>"
		+ "<option value='H10'>H10</option>"
		+ "<option value='H11'>H11</option>"
		+ "<option value='H12'>H12</option>"
		+ "<option value='H13'>H13</option>"
		+ "<option value='J1'>J1</option>"
		+ "<option value='J2'>J2</option>"
		+ "<option value='J3'>J3</option>"
		+ "<option value='J4'>J4</option>"
		+ "<option value='J5'>J5</option>"
		+ "<option value='J6'>J6</option>"
		+ "<option value='J7'>J7</option>"
		+ "<option value='J8'>J8</option>"
		+ "<option value='J9'>J9</option>"
		+ "<option value='J10'>J10</option>"
		+ "<option value='J11'>J11</option>"
		+ "<option value='J12'>J12</option>"
		+ "<option value='J13'>J13</option>"
		+ "<option value='K1'>K1</option>"
		+ "<option value='K2'>K2</option>"
		+ "<option value='K3'>K3</option>"
		+ "<option value='K4'>K4</option>"
		+ "<option value='K5'>K5</option>"
		+ "<option value='K6'>K6</option>"
		+ "<option value='K7'>K7</option>"
		+ "<option value='K8'>K8</option>"
		+ "<option value='K9'>K9</option>"
		+ "<option value='K10'>K10</option>"
		+ "<option value='K11'>K11</option>"
		+ "<option value='K12'>K12</option>"
		+ "<option value='K13'>K13</option>"
		+ "<option value='L1'>L1</option>"
		+ "<option value='L2'>L2</option>"
		+ "<option value='L3'>L3</option>"
		+ "<option value='L4'>L4</option>"
		+ "<option value='L5'>L5</option>"
		+ "<option value='L6'>L6</option>"
		+ "<option value='L7'>L7</option>"
		+ "<option value='L8'>L8</option>"
		+ "<option value='L9'>L9</option>"
		+ "<option value='L10'>L10</option>"
		+ "<option value='L11'>L11</option>"
		+ "<option value='L12'>L12</option>"
		+ "<option value='L13'>L13</option>"
		+ "<option value='M1'>M1</option>"
		+ "<option value='M2'>M2</option>"
		+ "<option value='M3'>M3</option>"
		+ "<option value='M4'>M4</option>"
		+ "<option value='M5'>M5</option>"
		+ "<option value='M6'>M6</option>"
		+ "<option value='M7'>M7</option>"
		+ "<option value='M8'>M8</option>"
		+ "<option value='M9'>M9</option>"
		+ "<option value='M10'>M10</option>"
		+ "<option value='M11'>M11</option>"
		+ "<option value='M12'>M12</option>"
		+ "<option value='M13'>M13</option>"
		+ "<option value='N1'>N1</option>"
		+ "<option value='N2'>N2</option>"
		+ "<option value='N3'>N3</option>"
		+ "<option value='N4'>N4</option>"
		+ "<option value='N5'>N5</option>"
		+ "<option value='N6'>N6</option>"
		+ "<option value='N7'>N7</option>"
		+ "<option value='N8'>N8</option>"
		+ "<option value='N9'>N9</option>"
		+ "<option value='N10'>N10</option>"
		+ "<option value='N11'>N11</option>"
		+ "<option value='N12'>N12</option>"
		+ "<option value='N13'>N13</option>"
		+ "</select>"
		+ " Force Format: <select name=,ff3[],>"
  		+ "	<option value='r_0'>R0</option>"
  		+ "	<option value='dnr_l'>DNRZ_L</option>"
		+ "</select>"
		+ " I/O: <select name='IO3[]'>"
  		+ "	<option value='input'>Input</option>"
  		+ "	<option value='output'>Output</option>"
  		+ "</select> "
  		+ " Test Cycle: <select name='test_cycle3[]'>"
  		+ "	<option value='test1'>1</option>"
  		+ "	<option value='test2'>2</option>"
  		+ "</select> "
  		+ "<br>"
		+"</li>");
    });
});

$(document).ready(function(){
    $("#remove_sig_temp3").click(function(){
        $("#signals3 li:last-child").remove();
    });
});



$(document).ready(function(){
    $("#add_sig_temp4").click(function(){
        $("#signals4").append("<li>Signal Name: <input type='text' name='signals4[]'>"
		+ " Signal Location: <select name='sig_loc4[]'>"
		+ "<option value='A1'>A1</option>"
		+ "<option value='A2'>A2</option>"
		+ "<option value='A3'>A3</option>"
		+ "<option value='A4'>A4</option>"
		+ "<option value='A5'>A5</option>"
		+ "<option value='A6'>A6</option>"
		+ "<option value='A7'>A7</option>"
		+ "<option value='A8'>A8</option>"
		+ "<option value='A9'>A9</option>"
		+ "<option value='A10'>A10</option>"
		+ "<option value='A11'>A11</option>"
		+ "<option value='A12'>A12</option>"
		+ "<option value='A13'>A13</option>"
		+ "<option value='B1'>B1</option>"
		+ "<option value='B2'>B2</option>"
		+ "<option value='B3'>B3</option>"
		+ "<option value='B4'>B4</option>"
		+ "<option value='B5'>B5</option>"
		+ "<option value='B6'>B6</option>"
		+ "<option value='B7'>B7</option>"
		+ "<option value='B8'>B8</option>"
		+ "<option value='B9'>B9</option>"
		+ "<option value='B10'>B10</option>"
		+ "<option value='B11'>B11</option>"
		+ "<option value='B12'>B12</option>"
		+ "<option value='B13'>B13</option>"
		+ "<option value='C1'>C1</option>"
		+ "<option value='C2'>C2</option>"
		+ "<option value='C3'>C3</option>"
		+ "<option value='C4'>C4</option>"
		+ "<option value='C5'>C5</option>"
		+ "<option value='C6'>C6</option>"
		+ "<option value='C7'>C7</option>"
		+ "<option value='C8'>C8</option>"
		+ "<option value='C9'>C9</option>"
		+ "<option value='C10'>C10</option>"
		+ "<option value='C11'>C11</option>"
		+ "<option value='C12'>C12</option>"
		+ "<option value='C13'>C13</option>"
		+ "<option value='D1'>D1</option>"
		+ "<option value='D2'>D2</option>"
		+ "<option value='D3'>D3</option>"
		+ "<option value='D4'>D4</option>"
		+ "<option value='D5'>D5</option>"
		+ "<option value='D6'>D6</option>"
		+ "<option value='D7'>D7</option>"
		+ "<option value='D8'>D8</option>"
		+ "<option value='D9'>D9</option>"
		+ "<option value='D10'>D10</option>"
		+ "<option value='D11'>D11</option>"
		+ "<option value='D12'>D12</option>"
		+ "<option value='D13'>D13</option>"
		+ "<option value='E1'>E1</option>"
		+ "<option value='E2'>E2</option>"
		+ "<option value='E3'>E3</option>"
		+ "<option value='E4'>E4</option>"
		+ "<option value='E5'>E5</option>"
		+ "<option value='E6'>E6</option>"
		+ "<option value='E7'>E7</option>"
		+ "<option value='E8'>E8</option>"
		+ "<option value='E9'>E9</option>"
		+ "<option value='E10'>E10</option>"
		+ "<option value='E11'>E11</option>"
		+ "<option value='E12'>E12</option>"
		+ "<option value='E13'>E13</option>"
		+ "<option value='F1'>F1</option>"
		+ "<option value='F2'>F2</option>"
		+ "<option value='F3'>F3</option>"
		+ "<option value='F4'>F4</option>"
		+ "<option value='F5'>F5</option>"
		+ "<option value='F6'>F6</option>"
		+ "<option value='F7'>F7</option>"
		+ "<option value='F8'>F8</option>"
		+ "<option value='F9'>F9</option>"
		+ "<option value='F10'>F10</option>"
		+ "<option value='F11'>F11</option>"
		+ "<option value='F12'>F12</option>"
		+ "<option value='F13'>F13</option>"
		+ "<option value='G1'>G1</option>"
		+ "<option value='G2'>G2</option>"
		+ "<option value='G3'>G3</option>"
		+ "<option value='G4'>G4</option>"
		+ "<option value='G5'>G5</option>"
		+ "<option value='G6'>G6</option>"
		+ "<option value='G7'>G7</option>"
		+ "<option value='G8'>G8</option>"
		+ "<option value='G9'>G9</option>"
		+ "<option value='G10'>G10</option>"
		+ "<option value='G11'>G11</option>"
		+ "<option value='G12'>G12</option>"
		+ "<option value='G13'>G13</option>"
		+ "<option value='H1'>H1</option>"
		+ "<option value='H2'>H2</option>"
		+ "<option value='H3'>H3</option>"
		+ "<option value='H4'>H4</option>"
		+ "<option value='H5'>H5</option>"
		+ "<option value='H6'>H6</option>"
		+ "<option value='H7'>H7</option>"
		+ "<option value='H8'>H8</option>"
		+ "<option value='H9'>H9</option>"
		+ "<option value='H10'>H10</option>"
		+ "<option value='H11'>H11</option>"
		+ "<option value='H12'>H12</option>"
		+ "<option value='H13'>H13</option>"
		+ "<option value='J1'>J1</option>"
		+ "<option value='J2'>J2</option>"
		+ "<option value='J3'>J3</option>"
		+ "<option value='J4'>J4</option>"
		+ "<option value='J5'>J5</option>"
		+ "<option value='J6'>J6</option>"
		+ "<option value='J7'>J7</option>"
		+ "<option value='J8'>J8</option>"
		+ "<option value='J9'>J9</option>"
		+ "<option value='J10'>J10</option>"
		+ "<option value='J11'>J11</option>"
		+ "<option value='J12'>J12</option>"
		+ "<option value='J13'>J13</option>"
		+ "<option value='K1'>K1</option>"
		+ "<option value='K2'>K2</option>"
		+ "<option value='K3'>K3</option>"
		+ "<option value='K4'>K4</option>"
		+ "<option value='K5'>K5</option>"
		+ "<option value='K6'>K6</option>"
		+ "<option value='K7'>K7</option>"
		+ "<option value='K8'>K8</option>"
		+ "<option value='K9'>K9</option>"
		+ "<option value='K10'>K10</option>"
		+ "<option value='K11'>K11</option>"
		+ "<option value='K12'>K12</option>"
		+ "<option value='K13'>K13</option>"
		+ "<option value='L1'>L1</option>"
		+ "<option value='L2'>L2</option>"
		+ "<option value='L3'>L3</option>"
		+ "<option value='L4'>L4</option>"
		+ "<option value='L5'>L5</option>"
		+ "<option value='L6'>L6</option>"
		+ "<option value='L7'>L7</option>"
		+ "<option value='L8'>L8</option>"
		+ "<option value='L9'>L9</option>"
		+ "<option value='L10'>L10</option>"
		+ "<option value='L11'>L11</option>"
		+ "<option value='L12'>L12</option>"
		+ "<option value='L13'>L13</option>"
		+ "<option value='M1'>M1</option>"
		+ "<option value='M2'>M2</option>"
		+ "<option value='M3'>M3</option>"
		+ "<option value='M4'>M4</option>"
		+ "<option value='M5'>M5</option>"
		+ "<option value='M6'>M6</option>"
		+ "<option value='M7'>M7</option>"
		+ "<option value='M8'>M8</option>"
		+ "<option value='M9'>M9</option>"
		+ "<option value='M10'>M10</option>"
		+ "<option value='M11'>M11</option>"
		+ "<option value='M12'>M12</option>"
		+ "<option value='M13'>M13</option>"
		+ "<option value='N1'>N1</option>"
		+ "<option value='N2'>N2</option>"
		+ "<option value='N3'>N3</option>"
		+ "<option value='N4'>N4</option>"
		+ "<option value='N5'>N5</option>"
		+ "<option value='N6'>N6</option>"
		+ "<option value='N7'>N7</option>"
		+ "<option value='N8'>N8</option>"
		+ "<option value='N9'>N9</option>"
		+ "<option value='N10'>N10</option>"
		+ "<option value='N11'>N11</option>"
		+ "<option value='N12'>N12</option>"
		+ "<option value='N13'>N13</option>"
		+ "</select>"
		+ " Force Format: <select name=,ff4[],>"
  		+ "	<option value='r_0'>R0</option>"
  		+ "	<option value='dnr_l'>DNRZ_L</option>"
		+ "</select>"
		+ " I/O: <select name='IO4[]'>"
  		+ "	<option value='input'>Input</option>"
  		+ "	<option value='output'>Output</option>"
  		+ "</select> "
  		+ " Test Cycle: <select name='test_cycle4[]'>"
  		+ "	<option value='test1'>1</option>"
  		+ "	<option value='test2'>2</option>"
  		+ "</select> "
  		+ "<br>"
		+"</li>");
    });
});

$(document).ready(function(){
    $("#remove_sig_temp4").click(function(){
        $("#signals4 li:last-child").remove();
    });
});
</script>
</head>
<body>
<form action="welcome.php" method="post">
Chip under test: <input type="text" name="chip_name"> <br>
<br>
Test Cycle configuration: <br>
Cycle Length (*10ns): <input type="text" name="cycle_len1"><br>
Leading Edge 1 (*10ns): <input type="text" name="lead_del1"><br>
Leading Edge 2 (*10ns): <input type="text" name="lead_del2"><br>
Trailing Edge Delay (*10ns): <input type="text" name="trail_del1"><br><br>
Custom Voltage Levels <br>
High: <input type="text" name="cust_high">
Low: <input type="text" name="cust_low"><br>
<br><br>

Schmoo VDD <select name="schmoo_vdd">
			<option value="yes">Yes</option>
  			<option value="no">No</option>
		</select>

High: <input type="text" name="schmoo_vdd_high">
Low: <input type="text" name="schmoo_vdd_low">
Step: <input type="text" name="scmoo_vdd_step">
GND: <input type="text" name="scmoo_vdd_gnd"><br>
<br>
Schmoo GND <select name="schmoo_gnd">
			<option value="yes">Yes</option>
  			<option value="no">No</option>
		</select>

High: <input type="text" name="schmoo_gnd_high">
Low: <input type="text" name="schmoo_gnd_low">
Step: <input type="text" name="scmoo_gnd_step">
VDD: <input type="text" name="scmoo_gnd_vdd"><br>
<br><br>

Signal and Template Configuration:<br>

Template 1
<ol id="signals1">
	<li>Signal Name: <input type="text" name="signals1[]">
		Signal Location: <select name="sig_loc1[]">
			<option value="A1">A1</option>
			<option value="A2">A2</option>
			<option value="A3">A3</option>
			<option value="A4">A4</option>
			<option value="A5">A5</option>
			<option value="A6">A6</option>
			<option value="A7">A7</option>
			<option value="A8">A8</option>
			<option value="A9">A9</option>
			<option value="A10">A10</option>
			<option value="A11">A11</option>
			<option value="A12">A12</option>
			<option value="A13">A13</option>
			<option value="B1">B1</option>
			<option value="B2">B2</option>
			<option value="B3">B3</option>
			<option value="B4">B4</option>
			<option value="B5">B5</option>
			<option value="B6">B6</option>
			<option value="B7">B7</option>
			<option value="B8">B8</option>
			<option value="B9">B9</option>
			<option value="B10">B10</option>
			<option value="B11">B11</option>
			<option value="B12">B12</option>
			<option value="B13">B13</option>
			<option value="C1">C1</option>
			<option value="C2">C2</option>
			<option value="C3">C3</option>
			<option value="C4">C4</option>
			<option value="C5">C5</option>
			<option value="C6">C6</option>
			<option value="C7">C7</option>
			<option value="C8">C8</option>
			<option value="C9">C9</option>
			<option value="C10">C10</option>
			<option value="C11">C11</option>
			<option value="C12">C12</option>
			<option value="C13">C13</option>
			<option value="D1">D1</option>
			<option value="D2">D2</option>
			<option value="D3">D3</option>
			<option value="D4">D4</option>
			<option value="D5">D5</option>
			<option value="D6">D6</option>
			<option value="D7">D7</option>
			<option value="D8">D8</option>
			<option value="D9">D9</option>
			<option value="D10">D10</option>
			<option value="D11">D11</option>
			<option value="D12">D12</option>
			<option value="D13">D13</option>
			<option value="E1">E1</option>
			<option value="E2">E2</option>
			<option value="E3">E3</option>
			<option value="E4">E4</option>
			<option value="E5">E5</option>
			<option value="E6">E6</option>
			<option value="E7">E7</option>
			<option value="E8">E8</option>
			<option value="E9">E9</option>
			<option value="E10">E10</option>
			<option value="E11">E11</option>
			<option value="E12">E12</option>
			<option value="E13">E13</option>
			<option value="F1">F1</option>
			<option value="F2">F2</option>
			<option value="F3">F3</option>
			<option value="F4">F4</option>
			<option value="F5">F5</option>
			<option value="F6">F6</option>
			<option value="F7">F7</option>
			<option value="F8">F8</option>
			<option value="F9">F9</option>
			<option value="F10">F10</option>
			<option value="F11">F11</option>
			<option value="F12">F12</option>
			<option value="F13">F13</option>
			<option value="G1">G1</option>
			<option value="G2">G2</option>
			<option value="G3">G3</option>
			<option value="G4">G4</option>
			<option value="G5">G5</option>
			<option value="G6">G6</option>
			<option value="G7">G7</option>
			<option value="G8">G8</option>
			<option value="G9">G9</option>
			<option value="G10">G10</option>
			<option value="G11">G11</option>
			<option value="G12">G12</option>
			<option value="G13">G13</option>
			<option value="H1">H1</option>
			<option value="H2">H2</option>
			<option value="H3">H3</option>
			<option value="H4">H4</option>
			<option value="H5">H5</option>
			<option value="H6">H6</option>
			<option value="H7">H7</option>
			<option value="H8">H8</option>
			<option value="H9">H9</option>
			<option value="H10">H10</option>
			<option value="H11">H11</option>
			<option value="H12">H12</option>
			<option value="H13">H13</option>
			<option value="J1">J1</option>
			<option value="J2">J2</option>
			<option value="J3">J3</option>
			<option value="J4">J4</option>
			<option value="J5">J5</option>
			<option value="J6">J6</option>
			<option value="J7">J7</option>
			<option value="J8">J8</option>
			<option value="J9">J9</option>
			<option value="J10">J10</option>
			<option value="J11">J11</option>
			<option value="J12">J12</option>
			<option value="J13">J13</option>
			<option value="K1">K1</option>
			<option value="K2">K2</option>
			<option value="K3">K3</option>
			<option value="K4">K4</option>
			<option value="K5">K5</option>
			<option value="K6">K6</option>
			<option value="K7">K7</option>
			<option value="K8">K8</option>
			<option value="K9">K9</option>
			<option value="K10">K10</option>
			<option value="K11">K11</option>
			<option value="K12">K12</option>
			<option value="K13">K13</option>
			<option value="L1">L1</option>
			<option value="L2">L2</option>
			<option value="L3">L3</option>
			<option value="L4">L4</option>
			<option value="L5">L5</option>
			<option value="L6">L6</option>
			<option value="L7">L7</option>
			<option value="L8">L8</option>
			<option value="L9">L9</option>
			<option value="L10">L10</option>
			<option value="L11">L11</option>
			<option value="L12">L12</option>
			<option value="L13">L13</option>
			<option value="M1">M1</option>
			<option value="M2">M2</option>
			<option value="M3">M3</option>
			<option value="M4">M4</option>
			<option value="M5">M5</option>
			<option value="M6">M6</option>
			<option value="M7">M7</option>
			<option value="M8">M8</option>
			<option value="M9">M9</option>
			<option value="M10">M10</option>
			<option value="M11">M11</option>
			<option value="M12">M12</option>
			<option value="M13">M13</option>
			<option value="N1">N1</option>
			<option value="N2">N2</option>
			<option value="N3">N3</option>
			<option value="N4">N4</option>
			<option value="N5">N5</option>
			<option value="N6">N6</option>
			<option value="N7">N7</option>
			<option value="N8">N8</option>
			<option value="N9">N9</option>
			<option value="N10">N10</option>
			<option value="N11">N11</option>
			<option value="N12">N12</option>
			<option value="N13">N13</option>
		</select>
		Force Format: <select name="ff1[]">
  			<option value="r_0">R0</option>
  			<option value="dnr_l">DNRZ_L</option>
		</select>
		I/O: <select name="IO1[]">
  			<option value="input">Input</option>
  			<option value="output">Output</option>
  		</select> 
  		Test Cycle: <select name="test_cycle1[]">
  			<option value="test1">1</option>
  			<option value="test2">2</option>
  		</select> 
  		<br>
	</li>	
</ol>


Template 2
<ol id="signals2">
	<li>Signal Name: <input type="text" name="signals2[]">
		Signal Location: <select name="sig_loc2[]">
						<option value="A1">A1</option>
			<option value="A2">A2</option>
			<option value="A3">A3</option>
			<option value="A4">A4</option>
			<option value="A5">A5</option>
			<option value="A6">A6</option>
			<option value="A7">A7</option>
			<option value="A8">A8</option>
			<option value="A9">A9</option>
			<option value="A10">A10</option>
			<option value="A11">A11</option>
			<option value="A12">A12</option>
			<option value="A13">A13</option>
			<option value="B1">B1</option>
			<option value="B2">B2</option>
			<option value="B3">B3</option>
			<option value="B4">B4</option>
			<option value="B5">B5</option>
			<option value="B6">B6</option>
			<option value="B7">B7</option>
			<option value="B8">B8</option>
			<option value="B9">B9</option>
			<option value="B10">B10</option>
			<option value="B11">B11</option>
			<option value="B12">B12</option>
			<option value="B13">B13</option>
			<option value="C1">C1</option>
			<option value="C2">C2</option>
			<option value="C3">C3</option>
			<option value="C4">C4</option>
			<option value="C5">C5</option>
			<option value="C6">C6</option>
			<option value="C7">C7</option>
			<option value="C8">C8</option>
			<option value="C9">C9</option>
			<option value="C10">C10</option>
			<option value="C11">C11</option>
			<option value="C12">C12</option>
			<option value="C13">C13</option>
			<option value="D1">D1</option>
			<option value="D2">D2</option>
			<option value="D3">D3</option>
			<option value="D4">D4</option>
			<option value="D5">D5</option>
			<option value="D6">D6</option>
			<option value="D7">D7</option>
			<option value="D8">D8</option>
			<option value="D9">D9</option>
			<option value="D10">D10</option>
			<option value="D11">D11</option>
			<option value="D12">D12</option>
			<option value="D13">D13</option>
			<option value="E1">E1</option>
			<option value="E2">E2</option>
			<option value="E3">E3</option>
			<option value="E4">E4</option>
			<option value="E5">E5</option>
			<option value="E6">E6</option>
			<option value="E7">E7</option>
			<option value="E8">E8</option>
			<option value="E9">E9</option>
			<option value="E10">E10</option>
			<option value="E11">E11</option>
			<option value="E12">E12</option>
			<option value="E13">E13</option>
			<option value="F1">F1</option>
			<option value="F2">F2</option>
			<option value="F3">F3</option>
			<option value="F4">F4</option>
			<option value="F5">F5</option>
			<option value="F6">F6</option>
			<option value="F7">F7</option>
			<option value="F8">F8</option>
			<option value="F9">F9</option>
			<option value="F10">F10</option>
			<option value="F11">F11</option>
			<option value="F12">F12</option>
			<option value="F13">F13</option>
			<option value="G1">G1</option>
			<option value="G2">G2</option>
			<option value="G3">G3</option>
			<option value="G4">G4</option>
			<option value="G5">G5</option>
			<option value="G6">G6</option>
			<option value="G7">G7</option>
			<option value="G8">G8</option>
			<option value="G9">G9</option>
			<option value="G10">G10</option>
			<option value="G11">G11</option>
			<option value="G12">G12</option>
			<option value="G13">G13</option>
			<option value="H1">H1</option>
			<option value="H2">H2</option>
			<option value="H3">H3</option>
			<option value="H4">H4</option>
			<option value="H5">H5</option>
			<option value="H6">H6</option>
			<option value="H7">H7</option>
			<option value="H8">H8</option>
			<option value="H9">H9</option>
			<option value="H10">H10</option>
			<option value="H11">H11</option>
			<option value="H12">H12</option>
			<option value="H13">H13</option>
			<option value="J1">J1</option>
			<option value="J2">J2</option>
			<option value="J3">J3</option>
			<option value="J4">J4</option>
			<option value="J5">J5</option>
			<option value="J6">J6</option>
			<option value="J7">J7</option>
			<option value="J8">J8</option>
			<option value="J9">J9</option>
			<option value="J10">J10</option>
			<option value="J11">J11</option>
			<option value="J12">J12</option>
			<option value="J13">J13</option>
			<option value="K1">K1</option>
			<option value="K2">K2</option>
			<option value="K3">K3</option>
			<option value="K4">K4</option>
			<option value="K5">K5</option>
			<option value="K6">K6</option>
			<option value="K7">K7</option>
			<option value="K8">K8</option>
			<option value="K9">K9</option>
			<option value="K10">K10</option>
			<option value="K11">K11</option>
			<option value="K12">K12</option>
			<option value="K13">K13</option>
			<option value="L1">L1</option>
			<option value="L2">L2</option>
			<option value="L3">L3</option>
			<option value="L4">L4</option>
			<option value="L5">L5</option>
			<option value="L6">L6</option>
			<option value="L7">L7</option>
			<option value="L8">L8</option>
			<option value="L9">L9</option>
			<option value="L10">L10</option>
			<option value="L11">L11</option>
			<option value="L12">L12</option>
			<option value="L13">L13</option>
			<option value="M1">M1</option>
			<option value="M2">M2</option>
			<option value="M3">M3</option>
			<option value="M4">M4</option>
			<option value="M5">M5</option>
			<option value="M6">M6</option>
			<option value="M7">M7</option>
			<option value="M8">M8</option>
			<option value="M9">M9</option>
			<option value="M10">M10</option>
			<option value="M11">M11</option>
			<option value="M12">M12</option>
			<option value="M13">M13</option>
			<option value="N1">N1</option>
			<option value="N2">N2</option>
			<option value="N3">N3</option>
			<option value="N4">N4</option>
			<option value="N5">N5</option>
			<option value="N6">N6</option>
			<option value="N7">N7</option>
			<option value="N8">N8</option>
			<option value="N9">N9</option>
			<option value="N10">N10</option>
			<option value="N11">N11</option>
			<option value="N12">N12</option>
			<option value="N13">N13</option>
		</select>
		Force Format: <select name="ff2[]">
  			<option value="r_0">R0</option>
  			<option value="dnr_l">DNRZ_L</option>
  		</select>
  		I/O: <select name="IO2[]">
  			<option value="input">Input</option>
  			<option value="output">Output</option>
  		</select> 
  		Test Cycle: <select name="test_cycle2[]">
  			<option value="test1">1</option>
  			<option value="test2">2</option>
  		</select> 
  		
  		<br>
	</li>	
</ol>

Template 3
<ol id="signals3">
	<li>Signal Name: <input type="text" name="signals3[]">
		Signal Location: <select name="sig_loc3[]">
						<option value="A1">A1</option>
			<option value="A2">A2</option>
			<option value="A3">A3</option>
			<option value="A4">A4</option>
			<option value="A5">A5</option>
			<option value="A6">A6</option>
			<option value="A7">A7</option>
			<option value="A8">A8</option>
			<option value="A9">A9</option>
			<option value="A10">A10</option>
			<option value="A11">A11</option>
			<option value="A12">A12</option>
			<option value="A13">A13</option>
			<option value="B1">B1</option>
			<option value="B2">B2</option>
			<option value="B3">B3</option>
			<option value="B4">B4</option>
			<option value="B5">B5</option>
			<option value="B6">B6</option>
			<option value="B7">B7</option>
			<option value="B8">B8</option>
			<option value="B9">B9</option>
			<option value="B10">B10</option>
			<option value="B11">B11</option>
			<option value="B12">B12</option>
			<option value="B13">B13</option>
			<option value="C1">C1</option>
			<option value="C2">C2</option>
			<option value="C3">C3</option>
			<option value="C4">C4</option>
			<option value="C5">C5</option>
			<option value="C6">C6</option>
			<option value="C7">C7</option>
			<option value="C8">C8</option>
			<option value="C9">C9</option>
			<option value="C10">C10</option>
			<option value="C11">C11</option>
			<option value="C12">C12</option>
			<option value="C13">C13</option>
			<option value="D1">D1</option>
			<option value="D2">D2</option>
			<option value="D3">D3</option>
			<option value="D4">D4</option>
			<option value="D5">D5</option>
			<option value="D6">D6</option>
			<option value="D7">D7</option>
			<option value="D8">D8</option>
			<option value="D9">D9</option>
			<option value="D10">D10</option>
			<option value="D11">D11</option>
			<option value="D12">D12</option>
			<option value="D13">D13</option>
			<option value="E1">E1</option>
			<option value="E2">E2</option>
			<option value="E3">E3</option>
			<option value="E4">E4</option>
			<option value="E5">E5</option>
			<option value="E6">E6</option>
			<option value="E7">E7</option>
			<option value="E8">E8</option>
			<option value="E9">E9</option>
			<option value="E10">E10</option>
			<option value="E11">E11</option>
			<option value="E12">E12</option>
			<option value="E13">E13</option>
			<option value="F1">F1</option>
			<option value="F2">F2</option>
			<option value="F3">F3</option>
			<option value="F4">F4</option>
			<option value="F5">F5</option>
			<option value="F6">F6</option>
			<option value="F7">F7</option>
			<option value="F8">F8</option>
			<option value="F9">F9</option>
			<option value="F10">F10</option>
			<option value="F11">F11</option>
			<option value="F12">F12</option>
			<option value="F13">F13</option>
			<option value="G1">G1</option>
			<option value="G2">G2</option>
			<option value="G3">G3</option>
			<option value="G4">G4</option>
			<option value="G5">G5</option>
			<option value="G6">G6</option>
			<option value="G7">G7</option>
			<option value="G8">G8</option>
			<option value="G9">G9</option>
			<option value="G10">G10</option>
			<option value="G11">G11</option>
			<option value="G12">G12</option>
			<option value="G13">G13</option>
			<option value="H1">H1</option>
			<option value="H2">H2</option>
			<option value="H3">H3</option>
			<option value="H4">H4</option>
			<option value="H5">H5</option>
			<option value="H6">H6</option>
			<option value="H7">H7</option>
			<option value="H8">H8</option>
			<option value="H9">H9</option>
			<option value="H10">H10</option>
			<option value="H11">H11</option>
			<option value="H12">H12</option>
			<option value="H13">H13</option>
			<option value="J1">J1</option>
			<option value="J2">J2</option>
			<option value="J3">J3</option>
			<option value="J4">J4</option>
			<option value="J5">J5</option>
			<option value="J6">J6</option>
			<option value="J7">J7</option>
			<option value="J8">J8</option>
			<option value="J9">J9</option>
			<option value="J10">J10</option>
			<option value="J11">J11</option>
			<option value="J12">J12</option>
			<option value="J13">J13</option>
			<option value="K1">K1</option>
			<option value="K2">K2</option>
			<option value="K3">K3</option>
			<option value="K4">K4</option>
			<option value="K5">K5</option>
			<option value="K6">K6</option>
			<option value="K7">K7</option>
			<option value="K8">K8</option>
			<option value="K9">K9</option>
			<option value="K10">K10</option>
			<option value="K11">K11</option>
			<option value="K12">K12</option>
			<option value="K13">K13</option>
			<option value="L1">L1</option>
			<option value="L2">L2</option>
			<option value="L3">L3</option>
			<option value="L4">L4</option>
			<option value="L5">L5</option>
			<option value="L6">L6</option>
			<option value="L7">L7</option>
			<option value="L8">L8</option>
			<option value="L9">L9</option>
			<option value="L10">L10</option>
			<option value="L11">L11</option>
			<option value="L12">L12</option>
			<option value="L13">L13</option>
			<option value="M1">M1</option>
			<option value="M2">M2</option>
			<option value="M3">M3</option>
			<option value="M4">M4</option>
			<option value="M5">M5</option>
			<option value="M6">M6</option>
			<option value="M7">M7</option>
			<option value="M8">M8</option>
			<option value="M9">M9</option>
			<option value="M10">M10</option>
			<option value="M11">M11</option>
			<option value="M12">M12</option>
			<option value="M13">M13</option>
			<option value="N1">N1</option>
			<option value="N2">N2</option>
			<option value="N3">N3</option>
			<option value="N4">N4</option>
			<option value="N5">N5</option>
			<option value="N6">N6</option>
			<option value="N7">N7</option>
			<option value="N8">N8</option>
			<option value="N9">N9</option>
			<option value="N10">N10</option>
			<option value="N11">N11</option>
			<option value="N12">N12</option>
			<option value="N13">N13</option>
		</select>
		Force Format: <select name="ff3[]">
  			<option value="r_0">R0</option>
  			<option value="dnr_l">DNRZ_L</option>
  		</select>
  		I/O: <select name="IO3[]">
  			<option value="input">Input</option>
  			<option value="output">Output</option>
  		</select> 
  		Test Cycle: <select name="test_cycle3[]">
  			<option value="test1">1</option>
  			<option value="test2">2</option>
  		</select> 
  		
  		<br>
	</li>	
</ol>

Template 4
<ol id="signals4">
	<li>Signal Name: <input type="text" name="signals4[]">
		Signal Location: <select name="sig_loc4[]">
						<option value="A1">A1</option>
			<option value="A2">A2</option>
			<option value="A3">A3</option>
			<option value="A4">A4</option>
			<option value="A5">A5</option>
			<option value="A6">A6</option>
			<option value="A7">A7</option>
			<option value="A8">A8</option>
			<option value="A9">A9</option>
			<option value="A10">A10</option>
			<option value="A11">A11</option>
			<option value="A12">A12</option>
			<option value="A13">A13</option>
			<option value="B1">B1</option>
			<option value="B2">B2</option>
			<option value="B3">B3</option>
			<option value="B4">B4</option>
			<option value="B5">B5</option>
			<option value="B6">B6</option>
			<option value="B7">B7</option>
			<option value="B8">B8</option>
			<option value="B9">B9</option>
			<option value="B10">B10</option>
			<option value="B11">B11</option>
			<option value="B12">B12</option>
			<option value="B13">B13</option>
			<option value="C1">C1</option>
			<option value="C2">C2</option>
			<option value="C3">C3</option>
			<option value="C4">C4</option>
			<option value="C5">C5</option>
			<option value="C6">C6</option>
			<option value="C7">C7</option>
			<option value="C8">C8</option>
			<option value="C9">C9</option>
			<option value="C10">C10</option>
			<option value="C11">C11</option>
			<option value="C12">C12</option>
			<option value="C13">C13</option>
			<option value="D1">D1</option>
			<option value="D2">D2</option>
			<option value="D3">D3</option>
			<option value="D4">D4</option>
			<option value="D5">D5</option>
			<option value="D6">D6</option>
			<option value="D7">D7</option>
			<option value="D8">D8</option>
			<option value="D9">D9</option>
			<option value="D10">D10</option>
			<option value="D11">D11</option>
			<option value="D12">D12</option>
			<option value="D13">D13</option>
			<option value="E1">E1</option>
			<option value="E2">E2</option>
			<option value="E3">E3</option>
			<option value="E4">E4</option>
			<option value="E5">E5</option>
			<option value="E6">E6</option>
			<option value="E7">E7</option>
			<option value="E8">E8</option>
			<option value="E9">E9</option>
			<option value="E10">E10</option>
			<option value="E11">E11</option>
			<option value="E12">E12</option>
			<option value="E13">E13</option>
			<option value="F1">F1</option>
			<option value="F2">F2</option>
			<option value="F3">F3</option>
			<option value="F4">F4</option>
			<option value="F5">F5</option>
			<option value="F6">F6</option>
			<option value="F7">F7</option>
			<option value="F8">F8</option>
			<option value="F9">F9</option>
			<option value="F10">F10</option>
			<option value="F11">F11</option>
			<option value="F12">F12</option>
			<option value="F13">F13</option>
			<option value="G1">G1</option>
			<option value="G2">G2</option>
			<option value="G3">G3</option>
			<option value="G4">G4</option>
			<option value="G5">G5</option>
			<option value="G6">G6</option>
			<option value="G7">G7</option>
			<option value="G8">G8</option>
			<option value="G9">G9</option>
			<option value="G10">G10</option>
			<option value="G11">G11</option>
			<option value="G12">G12</option>
			<option value="G13">G13</option>
			<option value="H1">H1</option>
			<option value="H2">H2</option>
			<option value="H3">H3</option>
			<option value="H4">H4</option>
			<option value="H5">H5</option>
			<option value="H6">H6</option>
			<option value="H7">H7</option>
			<option value="H8">H8</option>
			<option value="H9">H9</option>
			<option value="H10">H10</option>
			<option value="H11">H11</option>
			<option value="H12">H12</option>
			<option value="H13">H13</option>
			<option value="J1">J1</option>
			<option value="J2">J2</option>
			<option value="J3">J3</option>
			<option value="J4">J4</option>
			<option value="J5">J5</option>
			<option value="J6">J6</option>
			<option value="J7">J7</option>
			<option value="J8">J8</option>
			<option value="J9">J9</option>
			<option value="J10">J10</option>
			<option value="J11">J11</option>
			<option value="J12">J12</option>
			<option value="J13">J13</option>
			<option value="K1">K1</option>
			<option value="K2">K2</option>
			<option value="K3">K3</option>
			<option value="K4">K4</option>
			<option value="K5">K5</option>
			<option value="K6">K6</option>
			<option value="K7">K7</option>
			<option value="K8">K8</option>
			<option value="K9">K9</option>
			<option value="K10">K10</option>
			<option value="K11">K11</option>
			<option value="K12">K12</option>
			<option value="K13">K13</option>
			<option value="L1">L1</option>
			<option value="L2">L2</option>
			<option value="L3">L3</option>
			<option value="L4">L4</option>
			<option value="L5">L5</option>
			<option value="L6">L6</option>
			<option value="L7">L7</option>
			<option value="L8">L8</option>
			<option value="L9">L9</option>
			<option value="L10">L10</option>
			<option value="L11">L11</option>
			<option value="L12">L12</option>
			<option value="L13">L13</option>
			<option value="M1">M1</option>
			<option value="M2">M2</option>
			<option value="M3">M3</option>
			<option value="M4">M4</option>
			<option value="M5">M5</option>
			<option value="M6">M6</option>
			<option value="M7">M7</option>
			<option value="M8">M8</option>
			<option value="M9">M9</option>
			<option value="M10">M10</option>
			<option value="M11">M11</option>
			<option value="M12">M12</option>
			<option value="M13">M13</option>
			<option value="N1">N1</option>
			<option value="N2">N2</option>
			<option value="N3">N3</option>
			<option value="N4">N4</option>
			<option value="N5">N5</option>
			<option value="N6">N6</option>
			<option value="N7">N7</option>
			<option value="N8">N8</option>
			<option value="N9">N9</option>
			<option value="N10">N10</option>
			<option value="N11">N11</option>
			<option value="N12">N12</option>
			<option value="N13">N13</option>
		</select>
		Force Format: <select name="ff4[]">
  			<option value="r_0">R0</option>
  			<option value="dnr_l">DNRZ_L</option>
  		</select>
  		I/O: <select name="IO4[]">
  			<option value="input">Input</option>
  			<option value="output">Output</option>
  		</select> 
  		Test Cycle: <select name="test_cycle4[]">
  			<option value="test1">1</option>
  			<option value="test2">2</option>
  		</select> 
  		
  		<br>
	</li>	
</ol>



Test Vector Setup
<ol id="test_vectors">
	<li>Test Vectors: <input type="text" size="150" name="test[]"><br>
		Expected Result:  <input type="text" size="150" name="result[]"></li>
</ol>

<input type="submit">

</form>

<button id="add_sig_temp1">Append Signal to Template 1</button>
<button id="remove_sig_temp1">Remove Signal from Template 1</button><br>
<button id="add_sig_temp2">Append Signal to Template 2</button>
<button id="remove_sig_temp2">Remove Signal from Template 2</button><br>
<button id="add_sig_temp3">Append Signal to Template 3</button>
<button id="remove_sig_temp3">Remove Signal from Template 3</button><br>
<button id="add_sig_temp4">Append Signal to Template 4</button>
<button id="remove_sig_temp4">Remove Signal from Template 4</button><br>
<button id="add_test_vector">Append Test Vector</button>
<button id="remove_test_vector">Remove Test Vector</button><br>
</body>
</body>
</body>
</body>
</html>