#define check_SOQ2RFQ_acceptance_cxx
#include "150311_check_SOQ2RFQ_acceptance.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

const string output = "testout4.root";

void check_SOQ2RFQ_acceptance::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L 150311_check_SOQ2RFQ_acceptance.C
//      Root > 150311_check_SOQ2RFQ_acceptance t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

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


//for ellipse 
  TF1* f1 = new TF1("f1", 
		  "( x*([1]-[0])*sin([2])*cos([2]) + sqrt( x*x*sin([2])**2*cos([2])**2*([0]-[1])**2 - ([1]*sin([2])**2+[0]*cos([2])**2)*( x*x*([1]*cos([2])**2+[0]*sin([2])**2) -[0]*[1] )   )   )/( [0]*cos([2])**2+[1]*sin([2])**2 )", -120,120);

  TF1* f2 = new TF1("f2", 
		  "( x*([1]-[0])*sin([2])*cos([2]) - sqrt( x*x*sin([2])**2*cos([2])**2*([0]-[1])**2 - ([1]*sin([2])**2+[0]*cos([2])**2)*( x*x*([1]*cos([2])**2+[0]*sin([2])**2) -[0]*[1] )   )   )/( [0]*cos([2])**2+[1]*sin([2])**2 )", -120,120);
  double r1=1.8;
  double r2=52;
  double theta=-1.6/180*TMath::Pi();
  f1->SetParameter(0, r1*r1);
  f1->SetParameter(1, r2*r2);
  f1->SetParameter(2, theta);
  f2->SetParameter(0, r1*r1);
  f2->SetParameter(1, r2*r2);
  f2->SetParameter(2, theta);


  TFile* fF = new TFile(output.c_str(), "recreate");
  TTree* fT = new TTree("tree","tree");
  double ix, iy, iz, ike, ipx, ipy, ipz;
  double fx, fy, fz, fke, fpx, fpy, fpz;
  int    flag;
  int    id;
  fT -> Branch("ix",   &ix,  "ix/D");
  fT -> Branch("iy",   &iy,  "iy/D");
  fT -> Branch("iz",   &iz,  "iz/D");
  fT -> Branch("ipx",  &ipx, "ipx/D");
  fT -> Branch("ipy",  &ipy, "ipy/D");
  fT -> Branch("ipz",  &ipz, "ipz/D");
  fT -> Branch("fx",   &fx,  "fx/D");
  fT -> Branch("fy",   &fy,  "fy/D");
  fT -> Branch("fz",   &fz,  "fz/D");
  fT -> Branch("fpx",  &fpx, "fpx/D");
  fT -> Branch("fpy",  &fpy, "fpy/D");
  fT -> Branch("fpz",  &fpz, "fpz/D");
 
  fT -> Branch("flag",&flag, "flag/I");
  fT -> Branch("id",&id, "id/I");

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      fx  = -777;
      fy  = -777;
      fz  = -777;
      fpx = -777;
      fpy = -777;
      fpz = -777;
      

      for(int i=0; i<save_n; i++){

	if(save_detID[i]==654){
	fx  = save_x[i]-780;
	fy  = save_y[i];
	fz  = save_z[i];
	fpx = save_px[i];
	fpy = save_py[i];
	fpz = save_pz[i];
	}
      }
      ix  = muIniPosX-780;
      iy  = muIniPosY;
      iz  = muIniPosZ;
      ipx = muIniMomX;
      ipy = muIniMomY;
      ipz = muIniMomZ;
      id =  save_particleID[0];
      double xang = fpx/fpz*1000;
      double yang = fpy/fpz*1000;

      double check_x_hi  = f1->Eval(fx);
      double check_x_lo  = f2->Eval(fx);
      double check_y_hi  = f1->Eval(fy);
      double check_y_lo  = f2->Eval(fy);




      if( check_x_hi > xang && xang > check_x_lo &&
	  check_y_hi > yang && yang > check_y_lo  ){
	flag = 1;
      }
      else
	flag = 0;
      fT->Fill();

      // if (Cut(ientry) < 0) continue;
   }
   fT -> Write();
   fF -> Write();
   fF -> Close();
}
