
//string draw = "fpx/fpz*1000:fx>>fH(100,-10,10,100,-100,100)";
string draw = "fpx/fpz*1000:fx>>fH";
const int    np = 14;
const double dr = 1.0;
const double rcut[np] = 
  {30, 32, 34, 36, 38, 
   40, 42, 44, 46, 48,
   50, 52, 54, 56};

const string pdfname = "150312_pxpz_x_rcut";
void macro_150312_draw(string filename){
  TFile* fF = new TFile(filename.c_str(), "read");
  TTree* fT = (TTree*)fF->Get("tree");
  TH2F* fH = new TH2F("fH","", 100,-10,10,100,-100,100);
  fH -> SetXTitle("x(mm)");
  fH -> SetYTitle("px/pz (mrad)");
  gStyle -> SetOptStat(0000);
  TCanvas* c1 = new TCanvas("c1","c1");
  for(int i=0; i<np; i++){
    fH->SetTitle( Form( "Initial R=%.1lf ~ %.1lf mm" , rcut[i]-dr, rcut[i]+dr) );
    fT->Draw( draw.c_str() , Form("abs(sqrt(ix*ix+iy*iy)-%lf)<%lf", rcut[i],dr) );
    fH->Draw("");

    c1->Update();
    c1->Print( Form("%s_%02d.pdf", pdfname.c_str(), i));
    cin.get();

  }

}
