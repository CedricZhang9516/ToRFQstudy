#define usm_emit_cxx
#include "usm_emit.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#define DETID 654
void usm_emit::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L usm_emit.C
//      Root > usm_emit t
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
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   double xx = 0, xxp=0, xpxp=0, yy=0, yyp=0, ypyp=0;
   int nevt=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      for(int i=0; i<save_n; i++){
	if(save_detID[i] != DETID )
	  continue;
	//160920 add
	//if(det_VrtxParticleID[i]!=-13)continue;
	if(save_particleID[i]!=-13)continue;
	double xp = save_px[i]/save_pz[i] * 1e3;


	xx    += (save_x[i]-780) * (save_x[i]-780);
	xxp   += (save_x[i]-780) * save_px[i]/save_pz[i]*1000;
	xpxp  += save_px[i] * save_px[i]/save_pz[i]/save_pz[i]*1e6;
	yy    += save_y[i] * save_y[i];
	yyp   += save_y[i] * save_py[i]/save_pz[i]*1000;
	ypyp  += save_py[i] * save_py[i]/save_pz[i]/save_pz[i]*1e6;
	nevt++;
      }//save_n
   }
   xx /= 1.0*nevt;
   xxp /= 1.0*nevt;
   xpxp /= 1.0*nevt;
   yy /= 1.0*nevt;
   yyp /= 1.0*nevt;
   ypyp /= 1.0*nevt;

   double ke  = 5.65e-3;
   double mmu = 105.658;
   double b   = sqrt(2.0*ke*mmu+ke*ke)/(mmu+ke);
   double g   = (mmu+ke)/mmu;
   cout << b << endl;
   cout << g << endl;
   double ex = sqrt(xx*xpxp-xxp*xxp)*b*g;
   double ey = sqrt(yy*ypyp-yyp*yyp)*b*g;
   cout << ex << endl;
   cout << ey << endl;
}
