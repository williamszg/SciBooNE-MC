{

//###############################################|
//###   Rein-Sehgal Files for Neutrino Mode   ###|
//###############################################|
TFile *f1 = new TFile("../ROOTFILES/protonRS.root");

TH2D *hTotalProton2DRS = (TH2D*)f1->Get("Total2D");
TH1D *hTotalEnergyRS = (TH1D*)f1->Get("TotalE");
TH1D *hTotalMomentumRS = (TH1D*)f1->Get("TotalM");
TH1D *hTotalAngleRS = (TH1D*)f1->Get("TotalA");

TH2D *hSNSProton2DRS = (TH2D*)f1->Get("SNS2D");
TH1D *hSNSEnergyRS = (TH1D*)f1->Get("SNSE");
TH1D *hSNSMomentumRS = (TH1D*)f1->Get("SNSM");
TH1D *hSNSAngleRS = (TH1D*)f1->Get("SNSA");

hTotalEnergyRS->Sumw2();
hTotalMomentumRS->Sumw2();
hTotalAngleRS->Sumw2();
hSNSEnergyRS->Sumw2();
hSNSMomentumRS->Sumw2();
hSNSAngleRS->Sumw2();

//--- Defining the Ratio Histograms ---|
TH2D *Ratio2DRS = new TH2D("Ratio2DRS", "2D Efficiencies", 36, 0, 180, 20, 0, 2000);
TH1D *RatioEnergyRS = new TH1D("RatioEnergyRS", "Energy Efficiencies", 50, 0, 2500);
TH1D *RatioMomentumRS = new TH1D("RatioMomentumRS", "Momentum Efficiencies", 50, 0, 2500);
TH1D *RatioAngleRS = new TH1D("RatioAngleRS", "Angle Efficiencies", 60, 0, 180);
//###############################################|


//###############################################|
//###  Berger-Sehgal Files for Neutrino Mode  ###|
//###############################################|
TFile *f2 = new TFile("../ROOTFILES/protonBS.root");

TH2D *hTotalProton2DBS = (TH2D*)f2->Get("Total2D");
TH1D *hTotalEnergyBS = (TH1D*)f2->Get("TotalE");
TH1D *hTotalMomentumBS = (TH1D*)f2->Get("TotalM");
TH1D *hTotalAngleBS = (TH1D*)f2->Get("TotalA");

TH2D *hSNSProton2DBS = (TH2D*)f2->Get("SNS2D");
TH1D *hSNSEnergyBS = (TH1D*)f2->Get("SNSE");
TH1D *hSNSMomentumBS = (TH1D*)f2->Get("SNSM");
TH1D *hSNSAngleBS = (TH1D*)f2->Get("SNSA");

hTotalEnergyBS->Sumw2();
hTotalMomentumBS->Sumw2();
hTotalAngleBS->Sumw2();
hSNSEnergyBS->Sumw2();
hSNSMomentumBS->Sumw2();
hSNSAngleBS->Sumw2();

//--- Defining the Ratio Histograms ---|
TH2D *Ratio2DBS = new TH2D("Ratio2DBS", "2D Efficiencies", 36, 0, 180, 20, 0, 2000);
TH1D *RatioEnergyBS = new TH1D("RatioEnergyBS", "Energy Efficiencies", 50, 0, 2500);
TH1D *RatioMomentumBS = new TH1D("RatioMomentumBS", "Momentum Efficiencies", 50, 0, 2500);
TH1D *RatioAngleBS = new TH1D("RatioAngleBS", "Angle Efficiencies", 60, 0, 180);
//###############################################|


//###############################################|
//### Old Rein-Sehgal Files for Neutrino Mode ###|
//###############################################|
TFile *f3 = new TFile("../ROOTFILES/protonORS.root");

TH2D *hTotalProton2DORS = (TH2D*)f3->Get("Total2D");
TH1D *hTotalEnergyORS = (TH1D*)f3->Get("TotalE");
TH1D *hTotalMomentumORS = (TH1D*)f3->Get("TotalM");
TH1D *hTotalAngleORS = (TH1D*)f3->Get("TotalA");

TH2D *hSNSProton2DORS = (TH2D*)f3->Get("SNS2D");
TH1D *hSNSEnergyORS = (TH1D*)f3->Get("SNSE");
TH1D *hSNSMomentumORS = (TH1D*)f3->Get("SNSM");
TH1D *hSNSAngleORS = (TH1D*)f3->Get("SNSA");

hTotalEnergyORS->Sumw2();
hTotalMomentumORS->Sumw2();
hTotalAngleORS->Sumw2();
hSNSEnergyORS->Sumw2();
hSNSMomentumORS->Sumw2();
hSNSAngleORS->Sumw2();

//--- Defining the Ratio Histograms ---|
TH2D *Ratio2DORS = new TH2D("Ratio2DORS", "2D Efficiencies", 36, 0, 180, 20, 0, 2000);
TH1D *RatioEnergyORS = new TH1D("RatioEnergyORS", "Energy Efficiencies", 50, 0, 2500);
TH1D *RatioMomentumORS = new TH1D("RatioMomentumORS", "Momentum Efficiencies", 50, 0, 2500);
TH1D *RatioAngleORS = new TH1D("RatioAngleORS", "Angle Efficiencies", 60, 0, 180);
//###############################################|

}
