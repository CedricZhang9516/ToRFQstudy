double x,y,z,t;
const double xmin = 0;
const double xmax = 60;
const double zmin = 0;
const double zmax = 10;
const double ymin = -10;
const double ymax = 10;
const int    xnbin = 100;
const int    znbin = 40;
const int    ynbin = 100;
void macro_160211_2(){
  TH2F* fHr = new TH2F("fHr","",xnbin, xmin, xmax, ynbin, ymin, ymax);
  TH2F* fHz = new TH2F("fHz","",znbin, zmin, zmax, ynbin, ymin, ymax);
  ifstream f("output.txt");
  while(f>>x>>y>>z>>t){
    x = x-780;
    double r = sqrt(x*x+y*y);
    t = t*1000 - 477;
    fHr -> Fill(r,t);
    z += 845;
    cout << z << endl;
    if(r>10&&r<15)
      fHz -> Fill(z,t);
  }//
  //fHr -> Draw("colz");
  fHz -> Draw("colz");

  fHr -> SetXTitle("R_{ini.}[mm]");
  fHr -> SetYTitle("#DeltaT@RFQ_{in}[nsec]");
  fHz -> SetXTitle("Z_{ini.}[mm]");
  fHz -> SetYTitle("#DeltaT@RFQ_{in}[nsec]");
  fHz -> SetTitle ("R_{ini.} = 10-15 mm");
  fHr -> SetNdivisions(612,"Y");
  fHz -> SetNdivisions(612,"Y");

  gStyle -> SetOptStat(0000);
  gStyle -> SetPadGridY(1);
  TCanvas* c1 = new TCanvas("c1","c1",10,10,1200,600);
  c1 -> Divide(2,1);
  c1 -> cd(1);
  fHr -> Draw("colz");
  c1 -> cd(2);
  fHz -> Draw("colz");
  c1 -> cd();
}
