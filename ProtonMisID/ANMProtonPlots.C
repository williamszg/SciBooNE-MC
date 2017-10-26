{

//###############################################|
//###   Rein-Sehgal Files for Neutrino Mode   ###|
//###############################################|
TFile *f1 = new TFile("../ROOTFILES/AprotonRS.root");

TH2D *hTotalProton2DRS = (TH2D*)f1->Get("Total2D");
TH1D *hTotalEnergyRS = (TH1D*)f1->Get("TotalE");
TH1D *hTotalMomentumRS = (TH1D*)f1->Get("TotalM");
TH1D *hTotalAngleRS = (TH1D*)f1->Get("TotalA");

TH2D *hSNSProton2DRS = (TH2D*)f1->Get("NS2D");
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
TH2D *Ratio2DRS = new TH2D("Ratio2DRS", "2D Efficiencies", 36, 0, 180, 55, 0, 5500);
TH1D *RatioEnergyRS = new TH1D("RatioEnergyRS", "Energy Efficiencies", 55, 0, 5500);
TH1D *RatioMomentumRS = new TH1D("RatioMomentumRS", "Momentum Efficiencies", 55, 0, 5500);
TH1D *RatioAngleRS = new TH1D("RatioAngleRS", "Angle Efficiencies", 60, 0, 180);

//--- Formatting the Plot
Ratio2DRS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
Ratio2DRS->GetXaxis()->CenterTitle();
Ratio2DRS->GetYaxis()->SetTitle("Proton Momentum (MeV)");
Ratio2DRS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioEnergyRS->GetXaxis()->SetTitle("Proton Energy (MeV)");
RatioEnergyRS->GetXaxis()->CenterTitle();
RatioEnergyRS->GetYaxis()->SetTitle("Efficiency");
RatioEnergyRS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioMomentumRS->GetXaxis()->SetTitle("Proton Momentum (MeV)");
RatioMomentumRS->GetXaxis()->CenterTitle();
RatioMomentumRS->GetYaxis()->SetTitle("Efficiency");
RatioMomentumRS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioAngleRS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
RatioAngleRS->GetXaxis()->CenterTitle();
RatioAngleRS->GetYaxis()->SetTitle("Efficiency");
RatioAngleRS->GetYaxis()->CenterTitle();

Ratio2DRS->Divide(hSNSProton2DRS, hTotalProton2DRS);
RatioEnergyRS->Divide(hSNSEnergyRS, hTotalEnergyRS);
RatioMomentumRS->Divide(hSNSMomentumRS, hTotalMomentumRS);
RatioAngleRS->Divide(hSNSAngleRS, hTotalAngleRS);
//###############################################|


//###############################################|
//###  Berger-Sehgal Files for Neutrino Mode  ###|
//###############################################|
TFile *f2 = new TFile("../ROOTFILES/AprotonBS.root");

TH2D *hTotalProton2DBS = (TH2D*)f2->Get("Total2D");
TH1D *hTotalEnergyBS = (TH1D*)f2->Get("TotalE");
TH1D *hTotalMomentumBS = (TH1D*)f2->Get("TotalM");
TH1D *hTotalAngleBS = (TH1D*)f2->Get("TotalA");

TH2D *hSNSProton2DBS = (TH2D*)f2->Get("NS2D");
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
TH2D *Ratio2DBS = new TH2D("Ratio2DBS", "2D Efficiencies", 36, 0, 180, 55, 0, 5500);
TH1D *RatioEnergyBS = new TH1D("RatioEnergyBS", "Energy Efficiencies", 55, 0, 5500);
TH1D *RatioMomentumBS = new TH1D("RatioMomentumBS", "Momentum Efficiencies", 55, 0, 5500);
TH1D *RatioAngleBS = new TH1D("RatioAngleBS", "Angle Efficiencies", 60, 0, 180);

//--- Formatting the Plot
Ratio2DBS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
Ratio2DBS->GetXaxis()->CenterTitle();
Ratio2DBS->GetYaxis()->SetTitle("Proton Momentum (MeV)");
Ratio2DBS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioEnergyBS->GetXaxis()->SetTitle("Proton Energy (MeV)");
RatioEnergyBS->GetXaxis()->CenterTitle();
RatioEnergyBS->GetYaxis()->SetTitle("Efficiency");
RatioEnergyBS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioMomentumBS->GetXaxis()->SetTitle("Proton Momentum (MeV)");
RatioMomentumBS->GetXaxis()->CenterTitle();
RatioMomentumBS->GetYaxis()->SetTitle("Efficiency");
RatioMomentumBS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioAngleBS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
RatioAngleBS->GetXaxis()->CenterTitle();
RatioAngleBS->GetYaxis()->SetTitle("Efficiency");
RatioAngleBS->GetYaxis()->CenterTitle();

Ratio2DBS->Divide(hSNSProton2DBS, hTotalProton2DBS);
RatioEnergyBS->Divide(hSNSEnergyBS, hTotalEnergyBS);
RatioMomentumBS->Divide(hSNSMomentumBS, hTotalMomentumBS);
RatioAngleBS->Divide(hSNSAngleBS, hTotalAngleBS);
//###############################################|

TFile *TAcceptanceInfo = new TFile("../ROOTFILES/2DProtonAcceptancesANM.root", "RECREATE");

Ratio2DRS->Write();
Ratio2DBS->Write();

}
