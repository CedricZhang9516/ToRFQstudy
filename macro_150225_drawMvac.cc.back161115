//const string filename = "vacuum_emission-hline_ATH0475_BEAM150223_surfmu_at_focus_aftertune_p36init.root";
//const string filename = "vacuum_emission-hline_ATH0475_BEAM150223_surfmu_at_focus_aftertune_p36init_re.root";

//const string filename = "vacuum_emission-hline_ATH450_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root";
const string filename = "vacuum_emission-hline_ATH475_BEAMG-2EDM_output_1e6_gendat_afterfit_SEPON_sum.root";

//const string filename = "vacuum_emission-hline_ATH475_BEAM150419_surfmu_at_focus_aftertune_p36init_sepON_maxNevt.root";

TFile* fF;
TTree* fT;
const double tmin  = -1;
const double tmax  = 6;
//const double tbinw = 0.05;
const double tbinw = 0.05;
const int    tbinn = (int)((tmax-tmin)/tbinw);
const double zmin  = 0;
const double zmax  = 10;
const double zbinw = 1;
const int    zbinn = (int)((zmax-zmin)/zbinw);
const double rmin  = 0;
const double rmax  = 100;
const double rbinw = 2;
const int    rbinn = (int)((rmax-rmin)/rbinw);

TCanvas* c1;
void SetStyle(){
  gStyle->SetOptStat(0000);
  gStyle->SetPadGridX(0);
  gStyle->SetPadGridY(0);
  c1 = new TCanvas("c1","c1");

}
void draw_zdist_time(){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("vacMu");

  double zem_mm, vzem, tem_us;
  cout << fT -> GetEntries() << endl;
  fT -> SetBranchAddress("zem_mm", &zem_mm );
  fT -> SetBranchAddress("vzem",   &vzem );
  fT -> SetBranchAddress("tem_us", &tem_us );

  TH2F* fH2 = new TH2F("fH2","", tbinn, tmin, tmax, zbinn, zmin, zmax);
  for(int i=0; i<fT->GetEntries(); i++){
    fT -> GetEntry(i);
    for(int it=0; it<tbinn; it++){
      double t = tmin + tbinw * (0.5+it);
      fH2 -> Fill( t, zem_mm + vzem * (t -tem_us) );
    }//it
  }//i
  SetStyle();
  fH2 -> SetXTitle("usec (t - tem_us) ");
  fH2 -> SetYTitle("mm (zem_mm+vzem*(t-tem_us)) ");
  fH2->Draw("colz");
}


const double c = 2.99792458e5;
const double Mmu = 105.6583/1000;//GeV
void draw_nevt_time(){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("vacMu");

  double zem_mm, vzem, xem_mm, vxem, yem_mm, vyem; 
  double tem_us, tdecay_us;
  cout << fT -> GetEntries() << endl;
  fT -> SetBranchAddress("zem_mm", &zem_mm );
  fT -> SetBranchAddress("vzem",   &vzem );
  fT -> SetBranchAddress("yem_mm", &yem_mm );
  fT -> SetBranchAddress("vyem",   &vyem );
  fT -> SetBranchAddress("xem_mm", &xem_mm );
  fT -> SetBranchAddress("vxem",   &vxem );
  fT -> SetBranchAddress("tem_us", &tem_us );
  fT -> SetBranchAddress("tdecay_us", &tdecay_us );
  TH1F* fH1 = new TH1F("fH1","", tbinn, tmin, tmax);

  int nevt = 0;
  for(int i=0; i<fT->GetEntries(); i++){
    fT -> GetEntry(i);
    for(int it=0; it<tbinn; it++){
      double t = tmin + tbinw * (0.5+it);
      //fH2 -> Fill( t, zem_mm + vzem * (t -tem_us) );
      double z = zem_mm + vzem * (t -tem_us) ;
      double x = xem_mm + vxem * (t -tem_us) ;
      double y = yem_mm + vyem * (t -tem_us) ;

      //if( fabs(x)<20&&fabs(y)<20 && z >= 1 && z <= 6 && t<tdecay_us ){
      //if( sqrt(x*x+y*y)<31.5 && z >= 1 && z <= 6 && t<tdecay_us ){
      //if( sqrt(xem_mm*xem_mm+yem_mm*yem_mm)<31.5 && z >= 1 && z <= 6 && t<tdecay_us ){
      //if( z >= 1 && z <= 6 && t<tdecay_us ){
      //if( z >= 1 && z <= 6 && t<tdecay_us && fabs(y)<20 ){
      //if( z >= 1 && z <= 5 && t<tdecay_us && fabs(y)<20 ){
      if(  z >= 1 && z <= 6 && t < tdecay_us && t > tem_us){
	//if( z >= 1 && z <= 6 && t<tdecay_us ){
	fH1 -> Fill( t ); 
      }
    }//it
  }//i
  cout << nevt << endl;

  SetStyle();
  fH1->SetNdivisions(808,"Y");
  fH1->SetNdivisions(808,"X");
  fH1->SetXTitle("usec");
  //fH1->SetYTitle("event(|x,y|<20mm, z=1~6mm)");
  //fH1->SetYTitle("event(|R_{surf.}|<31.5mm, z=1~6mm)");
  fH1->SetYTitle("event");
  fH1->SetMarkerStyle(8);
  fH1->SetMaximum(3e4);
  //fH1->SetLineColor(2);
  fH1->SetTitle("z=1~6mm, t_{em.}<t<t_{decay}"); 
  //fH1->Draw("p");
  fH1->Draw("l");
}


void dump_nevt_time(string output_dat){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("vacMu");

  double zem_mm, vzem, xem_mm, vxem, yem_mm, vyem; 
  double tem_us, tdecay_us;
  cout << fT -> GetEntries() << endl;
  fT -> SetBranchAddress("zem_mm", &zem_mm );
  fT -> SetBranchAddress("vzem",   &vzem );
  fT -> SetBranchAddress("yem_mm", &yem_mm );
  fT -> SetBranchAddress("vyem",   &vyem );
  fT -> SetBranchAddress("xem_mm", &xem_mm );
  fT -> SetBranchAddress("vxem",   &vxem );
  fT -> SetBranchAddress("tem_us", &tem_us );
  fT -> SetBranchAddress("tdecay_us", &tdecay_us );
  ofstream wf(output_dat.c_str());
  int nevt = 0;
  //double t = 1.2;
  //double t = 1.07;
  //double t = 0.95; // for high stat, AT450
  double t = 0.9; // for high stat, AT450
  //double t = 1.1; //same as okada-san
  cout << "dumped with t=" << t << "usec events" << endl;
  int count = 0;
  for(int i=0; i<fT->GetEntries(); i++){
    fT -> GetEntry(i);


    //fH2 -> Fill( t, zem_mm + vzem * (t -tem_us) );
    double z = zem_mm + vzem * (t -tem_us) ;
    double x = xem_mm + vxem * (t -tem_us) ;
    double y = yem_mm + vyem * (t -tem_us) ;
    //if( sqrt(xem_mm*xem_mm+yem_mm*yem_mm)<31.5 && z >= 1 && z <= 6 && t<tdecay_us ){
    //if( fabs(x)<20&&fabs(y)<20 && z >= 1 && z <= 6 && t < tdecay_us && t > tem_us){
    if( fabs(x+1.02)<20&&fabs(y-0.95)<20 && z >= 1 && z <= 6 && t < tdecay_us && t > tem_us){
    //if( sqrt(x*x+y*y)<20 && z >= 1 && z <= 6 && t < tdecay_us){
    //if(  z >= 1 && z <= 6 && t < tdecay_us){
    //if(  z >= 1 && z <= 6 && t < tdecay_us && t > tem_us){
    //if(  z > 1 && z < 6 && t < tdecay_us && t > tem_us && sqrt(x*x+y*y)<20){
    //if( t < tdecay_us && t > tem_us && z <10 ){
      double v = sqrt(vxem*vxem + vyem*vyem + vzem*vzem);
      double xang = TMath::ASin(vxem/v)*1000 ;
      double yang = TMath::ASin(vyem/v)*1000 ;
      /*
      cout << x *0.1<< " " 
	 << xang << " " 
	 << y *0.1<< " " 
	 << yang << " "
	 << Mmu*v/c/sqrt(1.0-v*v/c/c) << " "
	 << z  << " "
	 << t  << " "
	 << "-1 -1" << endl;
      */
      wf << x *0.1<< " " 
	 << xang << " " 
	 << y *0.1<< " " 
	 << yang << " "
	 << Mmu*v/c/sqrt(1.0-v*v/c/c) << " "
	 << z  << " "
	 << t  << " "
	 << "-1 -1" << endl;
      nevt ++;
    }
  }//i
  cout << nevt << endl;
  wf.close();

}


void draw_xy_time(){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("vacMu");
  gStyle->SetPadRightMargin(0.1);
  double zem_mm, vzem, xem_mm, vxem, yem_mm, vyem; 
  double tem_us;
  cout << fT -> GetEntries() << endl;
  fT -> SetBranchAddress("zem_mm", &zem_mm );
  fT -> SetBranchAddress("vzem",   &vzem );
  fT -> SetBranchAddress("yem_mm", &yem_mm );
  fT -> SetBranchAddress("vyem",   &vyem );
  fT -> SetBranchAddress("xem_mm", &xem_mm );
  fT -> SetBranchAddress("vxem",   &vxem );
  fT -> SetBranchAddress("tem_us", &tem_us );

  TH2F* fH2 = new TH2F("fH2","", tbinn, tmin, tmax, rbinn, rmin, rmax);
  fH2 -> SetNdivisions(606,"Y");
  for(int i=0; i<fT->GetEntries(); i++){
    fT -> GetEntry(i);
    for(int it=0; it<tbinn; it++){
      double t = tmin + tbinw * (0.5+it);

      double z = zem_mm + vzem * (t -tem_us) ;
      double x = xem_mm + vxem * (t -tem_us) ;
      double y = yem_mm + vyem * (t -tem_us) ;
      double r = sqrt(x*x+y*y);
      fH2 -> Fill( t, fabs(x) );

    }//it
  }//i
  SetStyle();
  fH2->SetXTitle("usec");
  fH2->SetYTitle("X(mm)");
  fH2->Draw("colz");

}

void draw_xy_time(){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("vacMu");
  gStyle->SetPadRightMargin(0.1);
  double zem_mm, vzem, xem_mm, vxem, yem_mm, vyem; 
  double tem_us;
  cout << fT -> GetEntries() << endl;
  fT -> SetBranchAddress("zem_mm", &zem_mm );
  fT -> SetBranchAddress("vzem",   &vzem );
  fT -> SetBranchAddress("yem_mm", &yem_mm );
  fT -> SetBranchAddress("vyem",   &vyem );
  fT -> SetBranchAddress("xem_mm", &xem_mm );
  fT -> SetBranchAddress("vxem",   &vxem );
  fT -> SetBranchAddress("tem_us", &tem_us );

  TH2F* fH2 = new TH2F("fH2","", tbinn, tmin, tmax, rbinn, rmin, rmax);
  fH2 -> SetNdivisions(606,"Y");
  for(int i=0; i<fT->GetEntries(); i++){
    fT -> GetEntry(i);
    for(int it=0; it<tbinn; it++){
      double t = tmin + tbinw * (0.5+it);

      double z = zem_mm + vzem * (t -tem_us) ;
      double x = xem_mm + vxem * (t -tem_us) ;
      double y = yem_mm + vyem * (t -tem_us) ;
      double r = sqrt(x*x+y*y);
      fH2 -> Fill( t, fabs(x) );

    }//it
  }//i
  SetStyle();
  fH2->SetXTitle("usec");
  fH2->SetYTitle("X(mm)");
  fH2->Draw("colz");

}



void draw_xy(double t){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("vacMu");
  gStyle->SetPadRightMargin(0.1);
  double zem_mm, vzem, xem_mm, vxem, yem_mm, vyem; 
  double tem_us, tdecay_us;
  cout << fT -> GetEntries() << endl;
  fT -> SetBranchAddress("zem_mm", &zem_mm );
  fT -> SetBranchAddress("vzem",   &vzem );
  fT -> SetBranchAddress("yem_mm", &yem_mm );
  fT -> SetBranchAddress("vyem",   &vyem );
  fT -> SetBranchAddress("xem_mm", &xem_mm );
  fT -> SetBranchAddress("vxem",   &vxem );
  fT -> SetBranchAddress("tem_us", &tem_us );
  fT -> SetBranchAddress("tdecay_us", &tdecay_us );
  int bin = 40;
  double min = -80;
  double max = 80;
  TH2F* fH2 = new TH2F("fH2","", bin, min, max,bin, min, max);


  //fH2 -> SetNdivisions(606,"Y");


  for(int i=0; i<fT->GetEntries(); i++){
    fT -> GetEntry(i);
    double z = zem_mm + vzem * (t -tem_us) ;
    double x = xem_mm + vxem * (t -tem_us) ;
    double y = yem_mm + vyem * (t -tem_us) ;
    double r = sqrt(x*x+y*y);
    if(  z >= 1 && z <= 6 && t < tdecay_us)
      fH2 -> Fill( x, y );

  }//i
  SetStyle();
  fH2->SetXTitle("X(mm)");
  fH2->SetYTitle("Y(mm)");
  fH2->SetNdivisions(808,"X");
  fH2->SetNdivisions(808,"Y");

  fH2->Draw("colz");
  cout << "ent: " << fH2->GetEntries() << endl;
}
