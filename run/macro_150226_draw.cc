//const string filename = "data/wo_tuning.root";
//const string filename = "data/newSOA_wo_tuning.root";
TFile* fF;
TTree* fT;
const double xymin = -5;
const double xymax = 5;
const int    xynbin= 1000;
const double dmin = -100;
const double dmax = 100;
const int    dnbin= 1000;



void draw_spin(string filename){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("t1");
  //gStyle -> SetOptStat(1110);
  TH1F* fH = new TH1F("fH", "", 20,0.90,1.10);
  fT -> Project("fH","muIniPolZ");
  TH1F* fH2 = new TH1F("fH2", "", 20,0.90,1.1);
  fT -> Project("fH2","muTargetPolZ");

  fH -> SetXTitle("s_{z}");
  fH -> SetYTitle("Events");
  fH -> SetFillColor(3);
  fH -> SetLineColor(3);
  fH -> SetFillStyle(3325);
  fH2 -> SetFillColor(4);
  fH2 -> SetLineColor(4);
  fH2 -> SetFillStyle(3352);
  fH->Draw();
  fH2->Draw("same");

  TLegend* leg = new TLegend(0.65,0.65,0.92,0.9);
  leg -> SetShadowColor(0);
  leg -> SetFillColor(0);
  leg -> SetLineColor(0);
  leg -> AddEntry("fH", "USM", "lf");
  leg -> AddEntry("fH2", "RFQ entrance", "lf");
  leg -> Draw();
}
void draw_ke(string filename){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("t1");
  gStyle -> SetOptStat(1110);
  TH1F* fH = new TH1F("fH", "", 30,5.5,5.8);
  fT -> Project("fH","save_ke*1000", "save_particleID==-13");
  fH -> SetFillColor(3);
  fH -> SetXTitle("Kinetic Energy(keV)");
  fH -> SetYTitle("Events");
  fH->Draw();
}



void draw_xdx_ydy(string filename){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)fF->Get("t1");
  gStyle -> SetOptStat(0000);
  TH2F* fHxdx = new TH2F("fHxdx", "", xynbin, xymin, xymax, dnbin, dmin, dmax);
  fT -> Draw("save_px/save_pz*1000:save_x-780>>fHxdx", "save_particleID==-13&&save_detID==654");


  TH2F* fHydy = new TH2F("fHydy", "", xynbin, xymin, xymax, dnbin, dmin, dmax);
  fT -> Draw("save_py/save_pz*1000:save_y>>fHydy", "save_particleID==-13&&save_detID==654");

  fHxdx -> SetMarkerStyle(8);
  fHxdx -> SetMarkerSize (1);
  fHydy -> SetMarkerStyle(8);
  fHydy -> SetMarkerSize (1);
  fHxdx -> SetXTitle("mm");
  fHxdx -> SetYTitle("mrad");
  fHydy -> SetXTitle("mm");
  fHydy -> SetYTitle("mrad");
  fHxdx -> SetTitle ("px/pz VS x");
  fHydy -> SetTitle ("py/pz VS y");
  TCanvas* c1 = new TCanvas("c1","c1",10,10,1100,600);
  c1 -> Divide(2,1);
  c1 -> cd(1);
  fHxdx -> SetMarkerSize(0.01);
  fHydy -> SetMarkerSize(0.01);
  fHxdx -> Draw("p");
  cout << fHxdx -> GetEntries() << endl;
  c1 -> cd(2);
  fHydy -> Draw("p");
  c1 -> cd();
}
