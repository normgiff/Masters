<html>
<body>
<?php


$signals_1 = $_POST['signals1'];
$output = array();
$rv = 0;
$num = 0;

$json_sig = json_encode($signals_1);

foreach($_POST['signals1'] as $item)
{
	echo $item  . "<br>";
	#echo $num . "<br>";
	$num++;
}

exec("./a.out {$json_sig} {$num}",$output,$rv);

//if($rv!=0)
//{
//  die("failed got a return value of $rv\n");
//}

foreach($output as $line)
{
  echo("<p>$line</p>\n");
}




?>


</body>
</html>