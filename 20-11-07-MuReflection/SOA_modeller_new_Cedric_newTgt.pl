#!/usr/bin/perl
use Math::Trig;
$filename = "SOA_command_new_201130_reflection.comi";
#$op_name  = "SOA_new.op3";
$op_name  = "SOA_201130_reflection.op3";
open(IN, "> $filename");
$pi          = atan2(1,1)*4;

### ------ parameters ------ ###
$z_offset = -127.8-11.9-4.3;
#length
#$len_Tgt  = -0.3;
$len_Tgt  = 0.3;
$len_S1   = 2;
$len_S2   = 38;
#$len_S3   = 196;
$len_S3   = 216;
$len_S4   = 2;
#front position of Z
$z_Tgt    = -1.0*$len_Tgt;
#$z_S1     = $z_Tgt + $len_Tgt + 9.9; #TDR
#$z_S1     = $z_Tgt + $len_Tgt + 50; #2018/8/27, Cedric study
$z_S1     = $z_Tgt + $len_Tgt + 25; #2020/11/30, Cedric study, new multi-piece
$z_S2     = $z_S1  + $len_S1  + 10;
$z_S3     = $z_S2  + $len_S2  + 10;
$z_S4     = $z_S3  + $len_S3  + 10;
#outer radius
#$oR_Tgt   = 170/2;
#$oR_S1    = 170/2;
#$oR_S2    = 170/2;
#$oR_S3    = 170/2;
#$oR_S4    = 170/2;
#$oR_Tgt   = 170/2;
$oR_Tgt   = 300/2;
$oR_S1    = 300/2;
$oR_S2    = 300/2;
$oR_S3    = 300/2;
$oR_S4    = 300/2;
#inner radius
#$iR_Tgt   = 63/2;
#$iR_S1    = 76/2;
#$iR_S2    = 76/2;
#$iR_S3    = 140/2;
#$iR_S4    = 76/2;
$iR_Tgt   = 120/2;
$iR_S1    = 140/2;
$iR_S2    = 140/2;
$iR_S3    = 240/2;
#$iR_S4    = 120/2; #v1
$iR_S4    = 100/2;
#chamber(GND)
$iR_MC    = 251;
$oR_MC    = 252;
$len_MC   = 400;
$z_MC     = -0.5*$len_MC;
#$iR_muport= 121;
#$oR_muport= 122;
$iR_muport= 160;
$oR_muport= 161;
#$len_muport= 650;
#$len_muport= 850; #for field calcluation
$len_muport= 1550;
$z_muport  = -300;
#origin X, Y
$X = 0;
$Y = 0;
### ------ voltage setting ------ ###
$V_GND= 0;
#TDR
#$V_Tgt= 9003;
#$V_S1 = 8903;
#$V_S2 = 8594;
#$V_S3 = 7484;
#2018/8/27, Cedric study
#$V_Tgt= 9003;
#$V_S1 = 8003;
#$V_S2 = 7730;
#$V_S3 = 6730;
#2018/8/28, Cedric study
$V_Tgt= 9003;
$V_S1 = 7428;
#$V_S2 = 7170;
#$V_S3 = 6244;
#108028_2
#$V_S2 = 6800;
#$V_S3 = 6000;
#108028_3
#$V_S2 = 7300;
#$V_S3 = 6000;
#108028_4
$V_S2 = 7300;
$V_S3 = 5500;

#$V_S3 = 5484;#v3
$V_S4 = 0;


### ------ start to construct model ----- ###

$line = $line."ANALYSISDATA OPTION=ACTIVATE PROGRAM=TOSCAELEC \n";
print IN "$line"; $line="";
#Tgt
$name="Tgt";
$line = $line."CYLINDER Name='$name'  X0=$X Y0=$Y Z0=$z_Tgt X1=$X Y1=$Y Z1=$z_Tgt+$len_Tgt -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_Tgt MINORRADIUS=$oR_Tgt TOPRADIUS=$oR_Tgt SIDES=2 MATERIALLABEL='SUS' \n";
#$line = $line."CYLINDER Name='${name}_' X0=$X Y0=$Y Z0=$z_Tgt X1=$X Y1=$Y Z1=$z_Tgt+$len_Tgt -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$iR_Tgt MINORRADIUS=$iR_Tgt TOPRADIUS=$iR_Tgt SIDES=2 MATERIALLABEL='SUS' \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=${name}_ \n";
#$line = $line."COMBINE OPERATION=SUBTRACT +REGULAR \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";



#S2
$name="S2";
$line = $line."CYLINDER Name='$name'  X0=$X Y0=$Y Z0=$z_S2 X1=$X Y1=$Y Z1=$z_S2+$len_S2 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_S2 MINORRADIUS=$oR_S2 TOPRADIUS=$oR_S2 SIDES=2 MATERIALLABEL='SUS' \n";
$line = $line."CYLINDER Name='${name}_' X0=$X Y0=$Y Z0=$z_S2 X1=$X Y1=$Y Z1=$z_S2+$len_S2 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$iR_S2 MINORRADIUS=$iR_S2 TOPRADIUS=$iR_S2 SIDES=2 MATERIALLABEL='SUS' \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=${name}_ \n";
$line = $line."COMBINE OPERATION=SUBTRACT +REGULAR \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";

#S3
$name="S3";
$line = $line."CYLINDER Name='$name'  X0=$X Y0=$Y Z0=$z_S3 X1=$X Y1=$Y Z1=$z_S3+$len_S3 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_S3 MINORRADIUS=$oR_S3 TOPRADIUS=$oR_S3 SIDES=2 MATERIALLABEL='SUS' \n";
$line = $line."CYLINDER Name='${name}_' X0=$X Y0=$Y Z0=$z_S3 X1=$X Y1=$Y Z1=$z_S3+$len_S3 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$iR_S3 MINORRADIUS=$iR_S3 TOPRADIUS=$iR_S3 SIDES=2 MATERIALLABEL='SUS' \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=${name}_ \n";
$line = $line."COMBINE OPERATION=SUBTRACT +REGULAR \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";

#S4

$name="S4";
$line = $line."CYLINDER Name='$name'  X0=$X Y0=$Y Z0=$z_S4 X1=$X Y1=$Y Z1=$z_S4+$len_S4 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_S4 MINORRADIUS=$oR_S4 TOPRADIUS=$oR_S4 SIDES=2 MATERIALLABEL='SUS' \n";
$line = $line."CYLINDER Name='${name}_' X0=$X Y0=$Y Z0=$z_S4 X1=$X Y1=$Y Z1=$z_S4+$len_S4 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$iR_S4 MINORRADIUS=$iR_S4 TOPRADIUS=$iR_S4 SIDES=2 MATERIALLABEL='SUS' \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=${name}_ \n";
$line = $line."COMBINE OPERATION=SUBTRACT +REGULAR \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";



#MC
$name="MC";
$line = $line."CYLINDER Name='$name'  X0=$X Y0=$Y Z0=$z_MC X1=$X Y1=$Y Z1=$z_MC+$len_MC -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_MC MINORRADIUS=$oR_MC TOPRADIUS=$oR_MC SIDES=2 MATERIALLABEL='Air' \n";
#$line = $line."CYLINDER Name='${name}_' X0=$X Y0=$Y Z0=$z_MC X1=$X Y1=$Y Z1=$z_MC+$len_MC -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$iR_MC MINORRADIUS=$iR_MC TOPRADIUS=$iR_MC SIDES=2 MATERIALLABEL='SUS' \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=${name}_ \n";
#$line = $line."COMBINE OPERATION=SUBTRACT +REGULAR \n";
#$line = $line."PICK OPTION=RESET \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
$line = $line."TRANSFORM OPTION=APPLY KEEP=YES TYPE=ROTATE ROTU=1 ROTV=0 ROTW=0 ANGLE=90 \n";
$line = $line."PICK OPTION=RESET \n";
#MC TOP
#$line = $line."CYLINDER Name='${name}_top'  X0=$X Y0=$Y+$len_MC/2 Z0=0 X1=$X Y1=$Y+$len_MC/2+1 Z1=0 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_MC MINORRADIUS=$oR_MC TOPRADIUS=$oR_MC SIDES=2 MATERIALLABEL='SUS' \n";
#$line = $line."CYLINDER Name='${name}_bottom'  X0=$X Y0=$Y-$len_MC/2 Z0=0 X1=$X Y1=$Y-$len_MC/2-1 Z1=0 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_MC MINORRADIUS=$oR_MC TOPRADIUS=$oR_MC SIDES=2 MATERIALLABEL='SUS' \n";

#MC slow mu port
$name="muport";

$line = $line."CYLINDER Name='${name}'  X0=$X Y0=$Y Z0=$z_muport X1=$X Y1=$Y Z1=$z_muport+$len_muport -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_muport MINORRADIUS=$oR_muport TOPRADIUS=$oR_muport SIDES=2 MATERIALLABEL='Air' \n";
#$line = $line."CYLINDER Name='${name}_' X0=$X Y0=$Y Z0=$z_muport X1=$X Y1=$Y Z1=$z_muport+$len_muport -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$iR_muport MINORRADIUS=$iR_muport TOPRADIUS=$iR_muport SIDES=2 MATERIALLABEL='SUS' \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=${name}_ \n";
#$line = $line."COMBINE OPERATION=SUBTRACT +REGULAR \n";
#$line = $line."PICK OPTION=RESET \n";


$line = $line."PICK OPTION=RESET \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=MC \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=muport \n";
$line = $line."COMBINE OPERATION=UNION +REGULAR \n";
$line = $line."PICK OPTION=RESET \n";
#$line = $line."CYLINDER Name='${name}_up'  X0=$X Y0=$Y Z0=$z_muport X1=$X Y1=$Y Z1=$z_muport-1 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_muport MINORRADIUS=$oR_muport TOPRADIUS=$oR_muport SIDES=2 MATERIALLABEL='SUS' \n";
#$line = $line."CYLINDER Name='${name}_down'  X0=$X Y0=$Y Z0=$z_muport+$len_muport X1=$X Y1=$Y Z1=$z_muport+$len_muport+1 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_muport MINORRADIUS=$oR_muport TOPRADIUS=$oR_muport SIDES=2 MATERIALLABEL='SUS' \n";

print IN "$line"; $line="";



#surface
$line = $line."FILTER TYPE=FACE \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='Tgt' IDENTIFIER=A.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='Tgt' IDENTIFIER=A.00002 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='Tgt' IDENTIFIER=A.00003 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='Tgt' IDENTIFIER=A.00004 \n";
$line = $line."FACEDATA OPTION=MODIFY BOUNDARYLABEL='Tgt' LEVEL=50 ELEMENTTYPE=Linear FORMETHOD=NONE BACKMETHOD=NONE \n";
print IN "$line"; $line="";

#S1
$name="S1";
$line = $line."CYLINDER Name='$name'  X0=$X Y0=$Y Z0=$z_S1 X1=$X Y1=$Y Z1=$z_S1+$len_S1 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_S1 MINORRADIUS=$oR_S1 TOPRADIUS=$oR_S1 SIDES=2 MATERIALLABEL='Air' \n";
#$line = $line."CYLINDER Name='${name}_' X0=$X Y0=$Y Z0=$z_S1 X1=$X Y1=$Y Z1=$z_S1+$len_S1 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$iR_S1 MINORRADIUS=$iR_S1 TOPRADIUS=$iR_S1 SIDES=2 MATERIALLABEL='SUS' \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=$name \n";
#$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=${name}_ \n";
#$line = $line."COMBINE OPERATION=SUBTRACT +REGULAR \n";
$line = $line."PICK OPTION=RESET \n";

#S1
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='S1' IDENTIFIER=A.00004 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='S1' IDENTIFIER=A.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='S1' IDENTIFIER=A.00002 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='S1' IDENTIFIER=A.00003 \n";
$line = $line."FACEDATA OPTION=MODIFY BOUNDARYLABEL='S1' LEVEL=50 ELEMENTTYPE=Linear FORMETHOD=NONE BACKMETHOD=NONE \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";
#S2
$name="S2";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00004 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00002 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00003 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=B.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=B.00002 \n";
$line = $line."FACEDATA OPTION=MODIFY BOUNDARYLABEL='$name' LEVEL=50 ELEMENTTYPE=Linear FORMETHOD=NONE BACKMETHOD=NONE \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";

#S3
$name="S3";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00004 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00002 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00003 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=B.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=B.00002 \n";
$line = $line."FACEDATA OPTION=MODIFY BOUNDARYLABEL='$name' LEVEL=50 ELEMENTTYPE=Linear FORMETHOD=NONE BACKMETHOD=NONE \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";

#S4
$name="S4";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00004 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00002 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=A.00003 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=B.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='$name' IDENTIFIER=B.00002 \n";
$line = $line."FACEDATA OPTION=MODIFY BOUNDARYLABEL='$name' LEVEL=50 ELEMENTTYPE=Linear FORMETHOD=NONE BACKMETHOD=NONE \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";

#GND

$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=A.00002 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=A.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=A.00003 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=A.00004 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=C.00002 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=C.00001 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=C.00003 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=C.00004 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=B.00003 \n";
$line = $line."PICK OPTION=TOGGLE TYPE=FACE UNIQUEBODYNAME='MC' IDENTIFIER=B.00004 \n";

$line = $line."FACEDATA OPTION=MODIFY BOUNDARYLABEL='GND' LEVEL=50 ELEMENTTYPE=Linear FORMETHOD=NONE BACKMETHOD=NONE \n";
$line = $line."PICK OPTION=RESET \n";
print IN "$line"; $line="";


$line = $line."BOUNDARY PICK 'GND' \n";
$line = $line."BOUNDARY OPTION=MODIFY CONDITION=VOLTAGE VOLTAGE=$V_GND \n";
$line = $line."BOUNDARY UNPICK 'GND' | BOUNDARY PICK 'S1' \n";
$line = $line."BOUNDARY OPTION=MODIFY CONDITION=VOLTAGE VOLTAGE=$V_S1 \n";
$line = $line."BOUNDARY UNPICK 'S1' | BOUNDARY PICK 'Tgt' \n";
$line = $line."BOUNDARY OPTION=MODIFY CONDITION=VOLTAGE VOLTAGE=$V_Tgt \n";
$line = $line."BOUNDARY UNPICK 'Tgt' | BOUNDARY PICK 'S2' \n";
$line = $line."BOUNDARY OPTION=MODIFY CONDITION=VOLTAGE VOLTAGE=$V_S2 \n";
$line = $line."BOUNDARY UNPICK 'S2' | BOUNDARY PICK 'S3' \n";
$line = $line."BOUNDARY OPTION=MODIFY CONDITION=VOLTAGE VOLTAGE=$V_S3 \n";
$line = $line."BOUNDARY UNPICK 'S3' | BOUNDARY PICK 'S4' \n";
$line = $line."BOUNDARY OPTION=MODIFY CONDITION=VOLTAGE VOLTAGE=$V_S4 \n";
$line = $line."BOUNDARY OPTION=MODIFY CONDITION=VOLTAGE VOLTAGE=0 \n";
print IN "$line"; $line="";

#center is more finer
#$line = $line."CYLINDER Name='calTMP' X0=$X Y0=$Y Z0=$z_Tgt-2 X1=$X Y1=$Y Z1=$z_S4+$len_S4+2 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_S3 MINORRADIUS=$oR_S3 TOPRADIUS=$oR_S3 SIDES=2 MATERIALLABEL='Air' \n";
$line = $line."CYLINDER Name='calTMP' X0=$X Y0=$Y Z0=$z_Tgt-20 X1=$X Y1=$Y Z1=$z_S4+$len_S4+20 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=$oR_S3 MINORRADIUS=$oR_S3 TOPRADIUS=$oR_S3 SIDES=2 MATERIALLABEL='Air' \n";
#$line = $line."CYLINDER Name='calTMP' X0=$X Y0=$Y Z0=$z_Tgt-20 X1=$X Y1=$Y Z1=$z_S4+$len_S4+50 -TUBE SHAPECONTROL=SIMPLE MAJORRADIUS=100 MINORRADIUS=100 TOPRADIUS=100 SIDES=2 MATERIALLABEL='Air' \n";
$line = $line."PICK OPTION=RESET \n";
$line = $line."PICK OPTION=ADD, | PICK PROPERTY=Name LABEL=calTMP \n";
$line = $line."CELLDATA OPTION=MODIFY MATERIALLABEL='Air' POTENTIAL=Default ELEMENTTYPE=Linear LEVEL=100 SIZE=10 NORMALTOL=5 SURFACETOL=5 ELEMSHAPEPREF=NONE \n";
print IN "$line"; $line="";

#move for field map
print IN
"PICK OPTION=RESET
PICK OPTION=TOGGLE, | PICK PROPERTY=Name LABEL=calTMP
PICK OPTION=TOGGLE, | PICK PROPERTY=Name LABEL=MC
PICK OPTION=TOGGLE, | PICK PROPERTY=Name LABEL=S1
PICK OPTION=TOGGLE, | PICK PROPERTY=Name LABEL=S2
PICK OPTION=TOGGLE, | PICK PROPERTY=Name LABEL=S3
PICK OPTION=TOGGLE, | PICK PROPERTY=Name LABEL=S4
PICK OPTION=TOGGLE, | PICK PROPERTY=Name LABEL=Tgt
TRANSFORM OPTION=APPLY KEEP=YES TYPE=DISPLACE DU=0 DV=0 DW=$z_offset
PICK OPTION=RESET \n";
#material properties
$line = $line."MATERIALS GUIINIT \n";
$line = $line."MATERIALS PICK 'SUS' \n";
$line = $line."MATERIALS OPTION=RESET \n";
$line = $line."MATERIALS OPTION=MODIFY EPSANISOTROPY=ISOTROPIC EPSILON=1.0 SIGANISOTROPY=ISOTROPIC SIGMA=1.37E+06 \n";

$line = $line."MODEL CREATE \n";
$line = $line."MESH SIZE=30 NORMALTOL=20 SURFACETOL=0.0 TOLERANCE=1.0E-06 TYPE=PREFERTETRA \n";
$line = $line."FILL TOL=1.0E-06 \n";
$line = $line."SOLVERS SOLVENOW=YES SAVEMODEL=YES, | SOLVERS OPTION=TEST FILE='$op_name' UNITS=MM ELEMENT=MIXED SURFACE=CURVED | COMMENT CLEAR=YES TYPE=DBTITLE | SOLVERS OPTION=OVERWRITE \n";

print IN "$line"; $line="";

