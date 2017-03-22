//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan  5 14:06:47 2017 by ROOT version 6.06/00
// from TTree nRooTracker/Pure NEUT RooTracker
// found on file: SciBooNE_numubar_coh_RooTrack_NEW.root
//////////////////////////////////////////////////////////

#ifndef NewANMBergerSehgal_h
#define NewANMBergerSehgal_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TObjString.h"
#include "TObject.h"

class NewANMBergerSehgal {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
 //TObjString      *EvtCode;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   TString         fString;
   Int_t           EvtNum;
   Int_t           StdHepN;
   Int_t           StdHepPdg[24];   //[StdHepN]
   Int_t           StdHepStatus[24];   //[StdHepN]
   Double_t        StdHepP4[100][4];

   // List of branches
   TBranch        *b_EvtCode_fUniqueID;   //!
   TBranch        *b_EvtCode_fBits;   //!
   TBranch        *b_EvtCode_fString;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_StdHepN;   //!
   TBranch        *b_StdHepPdg;   //!
   TBranch        *b_StdHepStatus;   //!
   TBranch        *b_StdHepP4;   //!

   NewANMBergerSehgal(TTree *tree=0);
   virtual ~NewANMBergerSehgal();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef NewANMBergerSehgal_cxx
NewANMBergerSehgal::NewANMBergerSehgal(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SciBooNE_numubar_coh_RooTrack_NEW.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SciBooNE_numubar_coh_RooTrack_NEW.root");
      }
      f->GetObject("nRooTracker",tree);

   }
   Init(tree);
}

NewANMBergerSehgal::~NewANMBergerSehgal()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t NewANMBergerSehgal::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NewANMBergerSehgal::LoadTree(Long64_t entry)
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

void NewANMBergerSehgal::Init(TTree *tree)
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

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_EvtCode_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_EvtCode_fBits);
   fChain->SetBranchAddress("fString", &fString, &b_EvtCode_fString);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("StdHepN", &StdHepN, &b_StdHepN);
   fChain->SetBranchAddress("StdHepPdg", StdHepPdg, &b_StdHepPdg);
   fChain->SetBranchAddress("StdHepStatus", StdHepStatus, &b_StdHepStatus);
   fChain->SetBranchAddress("StdHepP4", StdHepP4, &b_StdHepP4);
   Notify();
}

Bool_t NewANMBergerSehgal::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void NewANMBergerSehgal::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t NewANMBergerSehgal::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef NewANMBergerSehgal_cxx
