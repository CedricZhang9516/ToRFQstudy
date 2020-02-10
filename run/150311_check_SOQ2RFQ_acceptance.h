//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 11 19:03:30 2015 by ROOT version 5.34/13
// from TTree t1/a simple Tree with simple variables
// found on file: data/musr_0.root
//////////////////////////////////////////////////////////

#ifndef check_SOQ2RFQ_acceptance_h
#define check_SOQ2RFQ_acceptance_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#define NDET 2
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class check_SOQ2RFQ_acceptance {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           runID;
   Int_t           eventID;
   Double_t        weight;
   Double_t        BFieldAtDecay_Bx;
   Double_t        BFieldAtDecay_By;
   Double_t        BFieldAtDecay_Bz;
   Double_t        BFieldAtDecay_B3;
   Double_t        BFieldAtDecay_B4;
   Double_t        BFieldAtDecay_B5;
   Double_t        muIniTime;
   Double_t        muIniPosX;
   Double_t        muIniPosY;
   Double_t        muIniPosZ;
   Double_t        muIniMomX;
   Double_t        muIniMomY;
   Double_t        muIniMomZ;
   Double_t        muIniPolX;
   Double_t        muIniPolY;
   Double_t        muIniPolZ;
   Int_t           muDecayDetID;
   Double_t        muDecayPosX;
   Double_t        muDecayPosY;
   Double_t        muDecayPosZ;
   Double_t        muDecayTime;
   Double_t        muDecayPolX;
   Double_t        muDecayPolY;
   Double_t        muDecayPolZ;
   Double_t        posIniMomX;
   Double_t        posIniMomY;
   Double_t        posIniMomZ;
   Int_t           nFieldNomVal;
   Double_t        fieldNomVal[NDET];   //[nFieldNomVal]
   Int_t           det_n;
   Int_t           det_ID[NDET];   //[det_n]
   Double_t        det_edep[NDET];   //[det_n]
   Double_t        det_edep_el[NDET];   //[det_n]
   Double_t        det_edep_pos[NDET];   //[det_n]
   Double_t        det_edep_gam[NDET];   //[det_n]
   Double_t        det_edep_mup[NDET];   //[det_n]
   Int_t           det_nsteps[NDET];   //[det_n]
   Double_t        det_length[NDET];   //[det_n]
   Double_t        det_time_start[NDET];   //[det_n]
   Double_t        det_time_end[NDET];   //[det_n]
   Double_t        det_x[NDET];   //[det_n]
   Double_t        det_y[NDET];   //[det_n]
   Double_t        det_z[NDET];   //[det_n]
   Double_t        det_kine[NDET];   //[det_n]
   Double_t        det_VrtxKine[NDET];   //[det_n]
   Double_t        det_VrtxX[NDET];   //[det_n]
   Double_t        det_VrtxY[NDET];   //[det_n]
   Double_t        det_VrtxZ[NDET];   //[det_n]
   Int_t           det_VrtxVolID[NDET];   //[det_n]
   Int_t           det_VrtxProcID[NDET];   //[det_n]
   Int_t           det_VrtxTrackID[NDET];   //[det_n]
   Int_t           det_VrtxParticleID[NDET];   //[det_n]
   Double_t        det_VvvKine[NDET];   //[det_n]
   Double_t        det_VvvX[NDET];   //[det_n]
   Double_t        det_VvvY[NDET];   //[det_n]
   Double_t        det_VvvZ[NDET];   //[det_n]
   Int_t           det_VvvVolID[NDET];   //[det_n]
   Int_t           det_VvvProcID[NDET];   //[det_n]
   Int_t           det_VvvTrackID[NDET];   //[det_n]
   Int_t           det_VvvParticleID[NDET];   //[det_n]
   Int_t           save_n;
   Int_t           save_detID[NDET];   //[save_n]
   Int_t           save_particleID[NDET];   //[save_n]
   Double_t        save_ke[NDET];   //[save_n]
   Double_t        save_x[NDET];   //[save_n]
   Double_t        save_y[NDET];   //[save_n]
   Double_t        save_z[NDET];   //[save_n]
   Double_t        save_px[NDET];   //[save_n]
   Double_t        save_py[NDET];   //[save_n]
   Double_t        save_pz[NDET];   //[save_n]


   // List of branches
   TBranch        *b_runID;   //!
   TBranch        *b_eventID;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_BFieldAtDecay;   //!
   TBranch        *b_muIniTime;   //!
   TBranch        *b_muIniPosX;   //!
   TBranch        *b_muIniPosY;   //!
   TBranch        *b_muIniPosZ;   //!
   TBranch        *b_muIniMomX;   //!
   TBranch        *b_muIniMomY;   //!
   TBranch        *b_muIniMomZ;   //!
   TBranch        *b_muIniPolX;   //!
   TBranch        *b_muIniPolY;   //!
   TBranch        *b_muIniPolZ;   //!
   TBranch        *b_muDecayDetID;   //!
   TBranch        *b_muDecayPosX;   //!
   TBranch        *b_muDecayPosY;   //!
   TBranch        *b_muDecayPosZ;   //!
   TBranch        *b_muDecayTime;   //!
   TBranch        *b_muDecayPolX;   //!
   TBranch        *b_muDecayPolY;   //!
   TBranch        *b_muDecayPolZ;   //!
   TBranch        *b_posIniMomX;   //!
   TBranch        *b_posIniMomY;   //!
   TBranch        *b_posIniMomZ;   //!
   TBranch        *b_nFieldNomVal;   //!
   TBranch        *b_fieldNomVal;   //!
   TBranch        *b_det_n;   //!
   TBranch        *b_det_ID;   //!
   TBranch        *b_det_edep;   //!
   TBranch        *b_det_edep_el;   //!
   TBranch        *b_det_edep_pos;   //!
   TBranch        *b_det_edep_gam;   //!
   TBranch        *b_det_edep_mup;   //!
   TBranch        *b_det_nsteps;   //!
   TBranch        *b_det_length;   //!
   TBranch        *b_det_time_start;   //!
   TBranch        *b_det_time_end;   //!
   TBranch        *b_det_x;   //!
   TBranch        *b_det_y;   //!
   TBranch        *b_det_z;   //!
   TBranch        *b_det_kine;   //!
   TBranch        *b_det_VrtxKine;   //!
   TBranch        *b_det_VrtxX;   //!
   TBranch        *b_det_VrtxY;   //!
   TBranch        *b_det_VrtxZ;   //!
   TBranch        *b_det_VrtxVolID;   //!
   TBranch        *b_det_VrtxProcID;   //!
   TBranch        *b_det_VrtxTrackID;   //!
   TBranch        *b_det_VrtxParticleID;   //!
   TBranch        *b_det_VvvKine;   //!
   TBranch        *b_det_VvvX;   //!
   TBranch        *b_det_VvvY;   //!
   TBranch        *b_det_VvvZ;   //!
   TBranch        *b_det_VvvVolID;   //!
   TBranch        *b_det_VvvProcID;   //!
   TBranch        *b_det_VvvTrackID;   //!
   TBranch        *b_det_VvvParticleID;   //!
   TBranch        *b_save_n;   //!
   TBranch        *b_save_detID;   //!
   TBranch        *b_save_particleID;   //!
   TBranch        *b_save_ke;   //!
   TBranch        *b_save_x;   //!
   TBranch        *b_save_y;   //!
   TBranch        *b_save_z;   //!
   TBranch        *b_save_px;   //!
   TBranch        *b_save_py;   //!
   TBranch        *b_save_pz;   //!

   check_SOQ2RFQ_acceptance(TTree *tree=0);
   virtual ~check_SOQ2RFQ_acceptance();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef check_SOQ2RFQ_acceptance_cxx
check_SOQ2RFQ_acceptance::check_SOQ2RFQ_acceptance(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("data/acccheck3.root");
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("data/150312_newSOA.root");
      if (!f || !f->IsOpen()) {
	f = new TFile("data/acccheck3.root");
	//f = new TFile("data/150312_newSOA.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

check_SOQ2RFQ_acceptance::~check_SOQ2RFQ_acceptance()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t check_SOQ2RFQ_acceptance::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t check_SOQ2RFQ_acceptance::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void check_SOQ2RFQ_acceptance::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runID", &runID, &b_runID);
   fChain->SetBranchAddress("eventID", &eventID, &b_eventID);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("BFieldAtDecay", &BFieldAtDecay_Bx, &b_BFieldAtDecay);
   fChain->SetBranchAddress("muIniTime", &muIniTime, &b_muIniTime);
   fChain->SetBranchAddress("muIniPosX", &muIniPosX, &b_muIniPosX);
   fChain->SetBranchAddress("muIniPosY", &muIniPosY, &b_muIniPosY);
   fChain->SetBranchAddress("muIniPosZ", &muIniPosZ, &b_muIniPosZ);
   fChain->SetBranchAddress("muIniMomX", &muIniMomX, &b_muIniMomX);
   fChain->SetBranchAddress("muIniMomY", &muIniMomY, &b_muIniMomY);
   fChain->SetBranchAddress("muIniMomZ", &muIniMomZ, &b_muIniMomZ);
   fChain->SetBranchAddress("muIniPolX", &muIniPolX, &b_muIniPolX);
   fChain->SetBranchAddress("muIniPolY", &muIniPolY, &b_muIniPolY);
   fChain->SetBranchAddress("muIniPolZ", &muIniPolZ, &b_muIniPolZ);
   fChain->SetBranchAddress("muDecayDetID", &muDecayDetID, &b_muDecayDetID);
   fChain->SetBranchAddress("muDecayPosX", &muDecayPosX, &b_muDecayPosX);
   fChain->SetBranchAddress("muDecayPosY", &muDecayPosY, &b_muDecayPosY);
   fChain->SetBranchAddress("muDecayPosZ", &muDecayPosZ, &b_muDecayPosZ);
   fChain->SetBranchAddress("muDecayTime", &muDecayTime, &b_muDecayTime);
   fChain->SetBranchAddress("muDecayPolX", &muDecayPolX, &b_muDecayPolX);
   fChain->SetBranchAddress("muDecayPolY", &muDecayPolY, &b_muDecayPolY);
   fChain->SetBranchAddress("muDecayPolZ", &muDecayPolZ, &b_muDecayPolZ);
   fChain->SetBranchAddress("posIniMomX", &posIniMomX, &b_posIniMomX);
   fChain->SetBranchAddress("posIniMomY", &posIniMomY, &b_posIniMomY);
   fChain->SetBranchAddress("posIniMomZ", &posIniMomZ, &b_posIniMomZ);
   fChain->SetBranchAddress("nFieldNomVal", &nFieldNomVal, &b_nFieldNomVal);
   fChain->SetBranchAddress("fieldNomVal", fieldNomVal, &b_fieldNomVal);
   fChain->SetBranchAddress("det_n", &det_n, &b_det_n);
   fChain->SetBranchAddress("det_ID", det_ID, &b_det_ID);
   fChain->SetBranchAddress("det_edep", det_edep, &b_det_edep);
   fChain->SetBranchAddress("det_edep_el", det_edep_el, &b_det_edep_el);
   fChain->SetBranchAddress("det_edep_pos", det_edep_pos, &b_det_edep_pos);
   fChain->SetBranchAddress("det_edep_gam", det_edep_gam, &b_det_edep_gam);
   fChain->SetBranchAddress("det_edep_mup", det_edep_mup, &b_det_edep_mup);
   fChain->SetBranchAddress("det_nsteps", det_nsteps, &b_det_nsteps);
   fChain->SetBranchAddress("det_length", det_length, &b_det_length);
   fChain->SetBranchAddress("det_time_start", det_time_start, &b_det_time_start);
   fChain->SetBranchAddress("det_time_end", det_time_end, &b_det_time_end);
   fChain->SetBranchAddress("det_x", det_x, &b_det_x);
   fChain->SetBranchAddress("det_y", det_y, &b_det_y);
   fChain->SetBranchAddress("det_z", det_z, &b_det_z);
   fChain->SetBranchAddress("det_kine", det_kine, &b_det_kine);
   fChain->SetBranchAddress("det_VrtxKine", det_VrtxKine, &b_det_VrtxKine);
   fChain->SetBranchAddress("det_VrtxX", det_VrtxX, &b_det_VrtxX);
   fChain->SetBranchAddress("det_VrtxY", det_VrtxY, &b_det_VrtxY);
   fChain->SetBranchAddress("det_VrtxZ", det_VrtxZ, &b_det_VrtxZ);
   fChain->SetBranchAddress("det_VrtxVolID", det_VrtxVolID, &b_det_VrtxVolID);
   fChain->SetBranchAddress("det_VrtxProcID", det_VrtxProcID, &b_det_VrtxProcID);
   fChain->SetBranchAddress("det_VrtxTrackID", det_VrtxTrackID, &b_det_VrtxTrackID);
   fChain->SetBranchAddress("det_VrtxParticleID", det_VrtxParticleID, &b_det_VrtxParticleID);
   fChain->SetBranchAddress("det_VvvKine", det_VvvKine, &b_det_VvvKine);
   fChain->SetBranchAddress("det_VvvX", det_VvvX, &b_det_VvvX);
   fChain->SetBranchAddress("det_VvvY", det_VvvY, &b_det_VvvY);
   fChain->SetBranchAddress("det_VvvZ", det_VvvZ, &b_det_VvvZ);
   fChain->SetBranchAddress("det_VvvVolID", det_VvvVolID, &b_det_VvvVolID);
   fChain->SetBranchAddress("det_VvvProcID", det_VvvProcID, &b_det_VvvProcID);
   fChain->SetBranchAddress("det_VvvTrackID", det_VvvTrackID, &b_det_VvvTrackID);
   fChain->SetBranchAddress("det_VvvParticleID", det_VvvParticleID, &b_det_VvvParticleID);
   fChain->SetBranchAddress("save_n", &save_n, &b_save_n);
   fChain->SetBranchAddress("save_detID", save_detID, &b_save_detID);
   fChain->SetBranchAddress("save_particleID", save_particleID, &b_save_particleID);
   fChain->SetBranchAddress("save_ke", save_ke, &b_save_ke);
   fChain->SetBranchAddress("save_x", save_x, &b_save_x);
   fChain->SetBranchAddress("save_y", save_y, &b_save_y);
   fChain->SetBranchAddress("save_z", save_z, &b_save_z);
   fChain->SetBranchAddress("save_px", save_px, &b_save_px);
   fChain->SetBranchAddress("save_py", save_py, &b_save_py);
   fChain->SetBranchAddress("save_pz", save_pz, &b_save_pz);
   Notify();
}

Bool_t check_SOQ2RFQ_acceptance::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void check_SOQ2RFQ_acceptance::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t check_SOQ2RFQ_acceptance::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef check_SOQ2RFQ_acceptance_cxx

