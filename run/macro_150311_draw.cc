
TFile* fF;
TTree* fT;
double ix,iy,iz, ipx, ipy, ipz;
double fx,fy,fz, fpx, fpy, fpz;
int flag;

const double min_dxy = -100;
const double max_dxy = -100;
//const double bin_dxy = 20;
const double bin_dxy = 1;
const double min_xy  = -80;
const double max_xy  = 80;
//const double bin_xy  = 10;
const double bin_xy  = 0.5;


const int    nbin_xy = (int)((max_xy-min_xy)/bin_xy);
const int    nbin_dxy= (int)((max_dxy-min_dxy)/bin_dxy);

TH2F* fH_wocut;
TH2F* fH_wcut;
TH2F* fHr;

void macro_150311_draw(string filename){
  fF = new TFile(filename.c_str(), "read");
  fT = (TTree*)(fF->Get("tree"));

  fT -> SetBranchAddress("ix",  &ix );
  fT -> SetBranchAddress("iy",  &iy );
  fT -> SetBranchAddress("iz",  &iz );
  fT -> SetBranchAddress("ipx", &ipx );
  fT -> SetBranchAddress("ipy", &ipy );
  fT -> SetBranchAddress("ipz", &ipz );
  fT -> SetBranchAddress("fx",  &fx );
  fT -> SetBranchAddress("fy",  &fy );
  fT -> SetBranchAddress("fz",  &fz );
  fT -> SetBranchAddress("fpx", &fpx );
  fT -> SetBranchAddress("fpy", &fpy );
  fT -> SetBranchAddress("fpz", &fpz );
  fT -> SetBranchAddress("fpz", &fpz );
  fT -> SetBranchAddress("flag", &flag );

  fH_wocut = new TH2F("fH_wocut","", nbin_xy, min_xy, max_xy, nbin_xy, min_xy, max_xy );
  fH_wcut  = new TH2F("fH_wcut","", nbin_xy, min_xy, max_xy, nbin_xy, min_xy, max_xy );
  //fH_wocut = new TH2F("fH_wocut","", nbin_xy, min_xy, max_xy, nbin_dxy, min_dxy, max_dxy);

  for(int i=0; i<fT->GetEntries(); i++){
    fT -> GetEntry(i);
    double dx = fpx/fpz*1000;
    double dy = fpy/fpz*1000;
    fH_wocut -> Fill(ix, iy);
    if(flag==1)
      fH_wcut -> Fill(ix, iy);


  }//
  fH_wcut->Draw("colz");
  fHr =  new TH2F("fHr","", nbin_xy, min_xy, max_xy, nbin_xy, min_xy, max_xy );
  fHr->Add(fH_wcut);
  fHr->Divide(fH_wocut);


  fHr->GetXaxis() -> SetTitle("x(mm)");
  fHr->GetYaxis() -> SetTitle("y(mm)");
  fHr->GetZaxis() -> SetTitle("acceptance");
  fHr->GetZaxis() -> SetTitleSize(0.05);
  fHr->GetZaxis() -> SetLabelSize(0.05);
  fHr->GetZaxis() -> SetRangeUser(0.4,1);
  fHr->SetNdivisions(404,"Z");
  fHr->SetNdivisions(808,"Y");
  fHr->SetNdivisions(808,"X");
  gStyle -> SetPadRightMargin(0.15); 
  gStyle -> SetPadGridX(1);
  gStyle -> SetPadGridY(1);
  gStyle -> SetOptStat(0000);
  TCanvas* c1 = new TCanvas("c1","c1");
  fHr->Draw("colz");
  fH_wocut->GetXaxis() -> SetTitle("x(mm)");
  fH_wocut->GetYaxis() -> SetTitle("y(mm)");


  fH_wcut -> SetMarkerStyle(8);
  fH_wcut -> SetMarkerColor(2);
  fH_wcut -> SetMarkerSize(0.2);
  fH_wocut -> SetMarkerStyle(8);
  fH_wocut -> SetMarkerColor(1);
  fH_wocut -> SetMarkerSize(0.2);
  fH_wocut->Draw("p");
  fH_wcut->Draw("p:same");
  
}
