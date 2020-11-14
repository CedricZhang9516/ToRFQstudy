#!/usr/bin/perl

$path="./";


open(RFILE,   "< $path/test_field_1203.table");
open(WWWFILE, "> $path/Field_PSI_1205_1.txt");
$i=-1;
print WWWFILE "29\t29\t120\tm\t0.00000100\n%nx\tny\tnz\tlength_unit\tnorm_fact\n%\n";
foreach $line(<RFILE>){
    $i++;
    if($i<8){
        next;
    }
    print WWWFILE $line;
}
close WWFILE;
close RFILE;

