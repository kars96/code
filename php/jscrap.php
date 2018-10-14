<?php
$html = file_get_contents('http://www.judgementstoday.com/judgements'); //get the html returned from the following url

$pokemon_doc = new DOMDocument();
$s = fopen("s", "w");
libxml_use_internal_errors(TRUE); //disable libxml errors

if(!empty($html)){ //if any html is actually returned

	$pokemon_doc->loadHTML($html);
	libxml_clear_errors(); //remove errors for yucky html
	
	$pokemon_xpath = new DOMXPath($pokemon_doc);

	//get all the h2's with an id
	$pokemon_row = $pokemon_xpath->query('//html');
	$st = "";
	if($pokemon_row->length > 0){
		foreach($pokemon_row as $row){
			$st=$s.$row->nodeValue . "<br/>";
		}
	}
	fwrite($s,$st);
}
?>