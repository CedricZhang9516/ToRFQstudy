#define okada_san_check_cxx
#include "okada_san_check.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
const string inifile = "../output_usm034a.dat";
const string outfile = "../output_usm034a_re_150420Doubled2.dat";
using namespace std;
#include <fstream.h>
void okada_san_check::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L okada_san_check.C
//      Root > okada_san_check t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//
  ifstream rf(inifile.c_str());
  ofstream wf(outfile.c_str());

  double  x,y,z,vx,vy,vz,en, fx,fy,fz,fvx,fvy,fvz,ft;

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   TH2F* fH2x = new TH2F("fH2x","fH2x", 1000,-5,5,1000,-5,5);
   TH2F* fH2y = new TH2F("fH2y","fH2y", 1000,-5,5,1000,-5,5);
   TH1F* fH = new TH1F("fH","fH", 1000,-5,5);
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      double vx_, vy_, vz_;
      vx_ = save_px[0]/sqrt(save_px[0]*save_px[0]+Mmu*Mmu);
      vy_ = save_py[0]/sqrt(save_py[0]*save_py[0]+Mmu*Mmu);
      vz_ = save_pz[0]/sqrt(save_pz[0]*save_pz[0]+Mmu*Mmu);


      rf >> x >> y >> z >> vx >> vy >> vz >> en >> fx >> fy >> fz >> fvx >> fvy >> fvz >> ft;
      wf<<x  << "\t"
	<<y  << "\t"
	<<z  << "\t"
	<<vx  << "\t"
	<<vy  << "\t"
	<<vz  << "\t"
	<<en  << "\t"
	<<fx  << "\t" << save_x[0]-780 << "\t"
	<<fy  << "\t" << save_y[0] << "\t"
	<<fz  << "\t" << save_z[0] << "\t"
	<<fvx << "\t" << vx_*3.0e8 << "\t"
	<<fvy<< "\t" << vy_*3.0e8 << "\t"
	<<fvz<< "\t" << vz_*3.0e8 << "\t"
	//<<ft <<endl;
	<<ft << "\t" << det_time_end[0]/1000. << "\t" 
	<<endl;
      fH2x->Fill(fx, save_x[0]-780);
      fH2y->Fill(fy, save_y[0]);
      fH  ->Fill(fx - (save_x[0]-780) );
      //fH  ->Fill( det_time_end[0]*1000.);
      //fH  ->Fill( ft*1000000.);
   }
   TCanvas* c1 = new TCanvas("c1","c1");
   c1->Divide(1,2);
   c1->cd(1);
   fH2x->Draw("");
   c1->cd(2);
   fH2y->Draw("");
   TCanvas* c2 = new TCanvas("c2","c2");
   fH->Draw();
}
