{
// ####################
// # Read in the Data #
// ####################

// =======================================================================================
//                ### Berger Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewBS = (TH1D*)f1->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewBS = (TH1D*)f1->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewBS = (TH1D*)f1->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewBS = (TH1D*)f1->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hGoodStoppedPNewBS = (TH1D*)f1->Get("GMuonMomS_1"); //Make a clone of the h6 histogram from the BergerSegal.C file for the good stopped muon momentum
TH1D *hGoodStoppedCosNewBS = (TH1D*)f1->Get("GMuonCosS_1"); //Make a clone of the h8 histogram from the BergerSegal.C file for the good stopped muon angle

TH1D *hGoodNonStoppedPNewBS = (TH1D*)f1->Get("GMuonMomNS_1"); //Make a clone of the h9 histogram from the BergerSegal.C file for the good nonstopped muon momentum
TH1D *hGoodNonStoppedCosNewBS = (TH1D*)f1->Get("GMuonCosNS_1"); //Make a clone of the h10 histogram from the BergerSegal.C file for the good nonstopped muon angle

TH1D *hTotalPNewBSCC = (TH1D*)f1->Get("CCTMuonMom_1"); //Make a clone of the h13 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewBSCC = (TH1D*)f1->Get("CCTGMuonMom_1"); //Make a clone of the h19 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewBSCC = (TH1D*)f1->Get("CCTMuonCos_1"); //Make a clone of the h14 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewBSCC = (TH1D*)f1->Get("CCTGMuonCos_1"); //Make a clone of the h20 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hPionEnergyBS = (TH1D*)f1->Get("TPionEnergy");
TH1D *hPionMomentumBS = (TH1D*)f1->Get("TPionMom");
TH1D *hPionAngleBS = (TH1D*)f1->Get("TPionAngle");

TH1D *hPionEnergyGoodBS = (TH1D*)f1->Get("GPionEnergy");
TH1D *hPionMomentumGoodBS = (TH1D*)f1->Get("GPionMom");
TH1D *hPionAngleGoodBS = (TH1D*)f1->Get("GPionAngle");

TH1D *hPionEnergyStoppedBS = (TH1D*)f1->Get("SPionEnergy");
TH1D *hPionMomentumStoppedBS = (TH1D*)f1->Get("SPionMom");
TH1D *hPionAngleStoppedBS = (TH1D*)f1->Get("SPionAngle");

TH1D *hPionEnergyNonStoppedBS = (TH1D*)f1->Get("NSPionEnergy");
TH1D *hPionMomentumNonStoppedBS = (TH1D*)f1->Get("NSPionMom");
TH1D *hPionAngleNonStoppedBS = (TH1D*)f1->Get("NSPionAngle");

TH1D *hPStoppedBSCC = (TH1D*)f1->Get("CCGMuonMomS_1");
TH1D *hCosStoppedBSCC = (TH1D*)f1->Get("CCGMuonCosS_1");
TH1D *hPNonStoppedBSCC = (TH1D*)f1->Get("CCGMuonMomNS_1");
TH1D *hCosNonStoppedBSCC = (TH1D*)f1->Get("CCGMuonCosNS_1");

TH2D *hTotalRatioBS = (TH2D*)f1->Get("T2D_1"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioBS = (TH2D*)f1->Get("G2D_1"); //Make a clone of the h22 histogram from the file


hTotalPNewBS->Sumw2();
hTotalGoodPNewBS->Sumw2();
hTotalCosNewBS->Sumw2();
hTotalGoodCosNewBS->Sumw2();
hGoodStoppedPNewBS->Sumw2();
hGoodStoppedCosNewBS->Sumw2();
hGoodNonStoppedPNewBS->Sumw2();
hGoodNonStoppedCosNewBS->Sumw2();
hTotalPNewBSCC->Sumw2();
hTotalGoodPNewBSCC->Sumw2();
hTotalCosNewBSCC->Sumw2();
hTotalGoodCosNewBSCC->Sumw2();
hPionEnergyBS->Sumw2();
hPionMomentumBS->Sumw2();
hPionAngleBS->Sumw2();
hPionEnergyGoodBS->Sumw2();
hPionMomentumGoodBS->Sumw2();
hPionAngleGoodBS->Sumw2();
hPionEnergyStoppedBS->Sumw2();
hPionMomentumStoppedBS->Sumw2();
hPionAngleStoppedBS->Sumw2();
hPionEnergyNonStoppedBS->Sumw2();
hPionMomentumNonStoppedBS->Sumw2();
hPionAngleNonStoppedBS->Sumw2();
hPStoppedBSCC->Sumw2();
hPNonStoppedBSCC->Sumw2();
hCosStoppedBSCC->Sumw2();
hCosNonStoppedBSCC->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPBS = new TH1D("RatioPBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCBS = new TH1D("RatioCBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioSPBS = new TH1D("RatioSPBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioSCBS = new TH1D("RatioSCBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioNSPBS = new TH1D("RatioNSPBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioNSCBS = new TH1D("RatioNSCBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPBSCC = new TH1D("RatioPBSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCBSCC = new TH1D("RatioCBSCC", "Efficiencies for Angles", 40, 0, 180);
TH1D *PionEnergyRatioBS = new TH1D("PionEnergyRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Energy", 40, 0, 2000);
TH1D *PionMomentumRatioBS = new TH1D("PionMomentumRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Momentum", 40, 0, 2000);
TH1D *PionAngleRatioBS = new TH1D("PionAngleRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioSBS = new TH1D("PionEnergyRatioSBS", "Pion Efficiencies for Stopped Muon Energy", 40, 0, 2000);
TH1D *PionMomentumRatioSBS = new TH1D("PionMomentumRatioSBS", "Pion Efficiencies for Stopped Muon Momentum", 40, 0, 2000);
TH1D *PionAngleRatioSBS = new TH1D("PionAngleRatioSBS", "Pion Efficiencies for Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioNSBS = new TH1D("PionEnergyRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Energy", 40, 0, 2000);
TH1D *PionMomentumRatioNSBS = new TH1D("PionMomentumRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Momentum", 40, 0, 2000);
TH1D *PionAngleRatioNSBS = new TH1D("PionAngleRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Angle", 40, 0, 180);
TH2D *Ratio2DBS = new TH2D("Ratio2DBS", "2D Efficiencies", 40, 0, 180, 40, 0, 2000);

// ### Formatting the plot ###
PionEnergyRatioBS->SetLineColor(kRed);
PionEnergyRatioBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioBS->GetXaxis()->CenterTitle();
PionEnergyRatioBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioBS->SetLineColor(kRed);
PionMomentumRatioBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioBS->GetXaxis()->CenterTitle();
PionMomentumRatioBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioBS->SetLineColor(kRed);
PionAngleRatioBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioBS->GetXaxis()->CenterTitle();
PionAngleRatioBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioSBS->SetLineColor(kRed);
PionEnergyRatioSBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioSBS->GetXaxis()->CenterTitle();
PionEnergyRatioSBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioSBS->SetLineColor(kRed);
PionMomentumRatioSBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioSBS->GetXaxis()->CenterTitle();
PionMomentumRatioSBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioSBS->SetLineColor(kRed);
PionAngleRatioSBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioSBS->GetXaxis()->CenterTitle();
PionAngleRatioSBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioNSBS->SetLineColor(kRed);
PionEnergyRatioNSBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioNSBS->GetXaxis()->CenterTitle();
PionEnergyRatioNSBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioNSBS->SetLineColor(kRed);
PionMomentumRatioNSBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioNSBS->GetXaxis()->CenterTitle();
PionMomentumRatioNSBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioNSBS->SetLineColor(kRed);
PionAngleRatioNSBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioNSBS->GetXaxis()->CenterTitle();
PionAngleRatioNSBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPBS->SetLineColor(kRed);
RatioPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBS->GetXaxis()->CenterTitle();
RatioPBS->GetYaxis()->SetTitle("Efficiency");
RatioPBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCBS->SetLineColor(kRed);
RatioCBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCBS->GetXaxis()->CenterTitle();
RatioCBS->GetYaxis()->SetTitle("Efficiency");
RatioCBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSPBS->SetLineColor(kRed);
RatioSPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioSPBS->GetXaxis()->CenterTitle();
RatioSPBS->GetYaxis()->SetTitle("Efficiency");
RatioSPBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSCBS->SetLineColor(kRed);
RatioSCBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioSCBS->GetXaxis()->CenterTitle();
RatioSCBS->GetYaxis()->SetTitle("Efficiency");
RatioSCBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSPBS->SetLineColor(kBlue);
RatioNSPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioNSPBS->GetXaxis()->CenterTitle();
RatioNSPBS->GetYaxis()->SetTitle("Efficiency");
RatioNSPBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSCBS->SetLineColor(kBlue);
RatioNSCBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioNSCBS->GetXaxis()->CenterTitle();
RatioNSCBS->GetYaxis()->SetTitle("Efficiency");
RatioNSCBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPBSCC->SetLineColor(kRed);
RatioPBSCC->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBSCC->GetXaxis()->CenterTitle();
RatioPBSCC->GetYaxis()->SetTitle("Efficiency");
RatioPBSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCBSCC->SetLineColor(kRed);
RatioCBSCC->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCBSCC->GetXaxis()->CenterTitle();
RatioCBSCC->GetYaxis()->SetTitle("Efficiency");
RatioCBSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
Ratio2DBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
Ratio2DBS->GetXaxis()->CenterTitle();
Ratio2DBS->GetYaxis()->SetTitle("Muon Momentum (MeV)");
Ratio2DBS->GetYaxis()->CenterTitle();


RatioPBS->Divide(hTotalGoodPNewBS, hTotalPNewBS);
RatioCBS->Divide(hTotalGoodCosNewBS, hTotalCosNewBS);
RatioSPBS->Divide(hPStoppedBSCC, hTotalGoodPNewBSCC);
RatioSCBS->Divide(hCosStoppedBSCC, hTotalGoodCosNewBSCC);
RatioNSPBS->Divide(hPNonStoppedBSCC, hTotalGoodPNewBSCC);
RatioNSCBS->Divide(hCosNonStoppedBSCC, hTotalGoodCosNewBSCC);
RatioPBSCC->Divide(hTotalGoodPNewBSCC, hTotalPNewBSCC);
RatioCBSCC->Divide(hTotalGoodCosNewBSCC, hTotalCosNewBSCC);
PionEnergyRatioBS->Divide(hPionEnergyGoodBS, hPionEnergyBS);
PionMomentumRatioBS->Divide(hPionMomentumGoodBS, hPionMomentumBS);
PionAngleRatioBS->Divide(hPionAngleGoodBS, hPionAngleBS);
PionEnergyRatioSBS->Divide(hPionEnergyStoppedBS, hPionEnergyGoodBS);
PionMomentumRatioSBS->Divide(hPionMomentumStoppedBS, hPionMomentumGoodBS);
PionAngleRatioSBS->Divide(hPionAngleStoppedBS, hPionAngleGoodBS);
PionEnergyRatioNSBS->Divide(hPionEnergyNonStoppedBS, hPionEnergyGoodBS);
PionMomentumRatioNSBS->Divide(hPionMomentumNonStoppedBS, hPionMomentumGoodBS);
PionAngleRatioNSBS->Divide(hPionAngleNonStoppedBS, hPionAngleGoodBS);
Ratio2DBS->Divide(hGoodRatioBS, hTotalRatioBS);




// =======================================================================================
//                    ### Rein Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f2 = new TFile("./ROOTFILES/totalmuoninfoRSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewRS = (TH1D*)f2->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRS = (TH1D*)f2->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRS = (TH1D*)f2->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRS = (TH1D*)f2->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hGoodStoppedPNewRS = (TH1D*)f2->Get("GMuonMomS_1"); //Make a clone of the h6 histogram from the BergerSegal.C file for the good stopped muon momentum
TH1D *hGoodStoppedCosNewRS = (TH1D*)f2->Get("GMuonCosS_1"); //Make a clone of the h8 histogram from the BergerSegal.C file for the good stopped muon angle

TH1D *hGoodNonStoppedPNewRS = (TH1D*)f2->Get("GMuonMomNS_1"); //Make a clone of the h9 histogram from the BergerSegal.C file for the good nonstopped muon momentum
TH1D *hGoodNonStoppedCosNewRS = (TH1D*)f2->Get("GMuonCosNS_1"); //Make a clone of the h10 histogram from the BergerSegal.C file for the good nonstopped muon angle

TH1D *hTotalPNewRSCC = (TH1D*)f2->Get("CCTMuonMom_1"); //Make a clone of the h13 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRSCC = (TH1D*)f2->Get("CCTGMuonMom_1"); //Make a clone of the h19 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRSCC = (TH1D*)f2->Get("CCTMuonCos_1"); //Make a clone of the h14 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRSCC = (TH1D*)f2->Get("CCTGMuonCos_1"); //Make a clone of the h20 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hPionEnergyRS = (TH1D*)f2->Get("TPionEnergy");
TH1D *hPionMomentumRS = (TH1D*)f2->Get("TPionMom");
TH1D *hPionAngleRS = (TH1D*)f2->Get("TPionAngle");

TH1D *hPionEnergyGoodRS = (TH1D*)f2->Get("GPionEnergy");
TH1D *hPionMomentumGoodRS = (TH1D*)f2->Get("GPionMom");
TH1D *hPionAngleGoodRS = (TH1D*)f2->Get("GPionAngle");

TH1D *hPionEnergyStoppedRS = (TH1D*)f2->Get("SPionEnergy");
TH1D *hPionMomentumStoppedRS = (TH1D*)f2->Get("SPionMom");
TH1D *hPionAngleStoppedRS = (TH1D*)f2->Get("SPionAngle");

TH1D *hPionEnergyNonStoppedRS = (TH1D*)f2->Get("NSPionEnergy");
TH1D *hPionMomentumNonStoppedRS = (TH1D*)f2->Get("NSPionMom");
TH1D *hPionAngleNonStoppedRS = (TH1D*)f2->Get("NSPionAngle");

TH2D *hTotalRatioRS = (TH2D*)f2->Get("T2D_1"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioRS = (TH2D*)f2->Get("G2D_1"); //Make a clone of the h22 histogram from the file


hTotalPNewRS->Sumw2();
hTotalGoodPNewRS->Sumw2();
hTotalCosNewRS->Sumw2();
hTotalGoodCosNewRS->Sumw2();
hGoodStoppedPNewRS->Sumw2();
hGoodStoppedCosNewRS->Sumw2();
hGoodNonStoppedPNewRS->Sumw2();
hGoodNonStoppedCosNewRS->Sumw2();
hTotalPNewRSCC->Sumw2();
hTotalGoodPNewRSCC->Sumw2();
hTotalCosNewRSCC->Sumw2();
hTotalGoodCosNewRSCC->Sumw2();
hPionEnergyRS->Sumw2();
hPionMomentumRS->Sumw2();
hPionAngleRS->Sumw2();
hPionEnergyGoodRS->Sumw2();
hPionMomentumGoodRS->Sumw2();
hPionAngleGoodRS->Sumw2();
hPionEnergyStoppedRS->Sumw2();
hPionMomentumStoppedRS->Sumw2();
hPionAngleStoppedRS->Sumw2();
hPionEnergyNonStoppedRS->Sumw2();
hPionMomentumNonStoppedRS->Sumw2();
hPionAngleNonStoppedRS->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPRS = new TH1D("RatioPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRS = new TH1D("RatioCRS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioSPRS = new TH1D("RatioSPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioSCRS = new TH1D("RatioSCRS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioNSPRS = new TH1D("RatioNSPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioNSCRS = new TH1D("RatioNSCRS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPRSCC = new TH1D("RatioPRSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRSCC = new TH1D("RatioCRSCC", "Efficiencies for Angles", 40, 0, 180);
TH1D *PionEnergyRatioRS = new TH1D("PionEnergyRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Energy", 40, 0, 2000);
TH1D *PionMomentumRatioRS = new TH1D("PionMomentumRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Momentum", 40, 0, 2000);
TH1D *PionAngleRatioRS = new TH1D("PionAngleRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioSRS = new TH1D("PionEnergyRatioSRS", "Pion Efficiencies for Stopped Muon Energy", 40, 0, 2000);
TH1D *PionMomentumRatioSRS = new TH1D("PionMomentumRatioSRS", "Pion Efficiencies for Stopped Muon Momentum", 40, 0, 2000);
TH1D *PionAngleRatioSRS = new TH1D("PionAngleRatioSRS", "Pion Efficiencies for Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioNSRS = new TH1D("PionEnergyRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Energy", 40, 0, 2000);
TH1D *PionMomentumRatioNSRS = new TH1D("PionMomentumRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Momentum", 40, 0, 2000);
TH1D *PionAngleRatioNSRS = new TH1D("PionAngleRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Angle", 40, 0, 180);
TH2D *Ratio2DRS = new TH2D("Ratio2DRS", "2D Efficiencies", 40, 0, 180, 40, 0, 2000);

// ### Formatting the plot ###
PionEnergyRatioRS->SetLineColor(kBlue);
PionEnergyRatioRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioRS->GetXaxis()->CenterTitle();
PionEnergyRatioRS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioRS->SetLineColor(kBlue);
PionMomentumRatioRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioRS->GetXaxis()->CenterTitle();
PionMomentumRatioRS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioRS->SetLineColor(kBlue);
PionAngleRatioRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioRS->GetXaxis()->CenterTitle();
PionAngleRatioRS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioSRS->SetLineColor(kBlue);
PionEnergyRatioSRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioSRS->GetXaxis()->CenterTitle();
PionEnergyRatioSRS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioSRS->SetLineColor(kBlue);
PionMomentumRatioSRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioSRS->GetXaxis()->CenterTitle();
PionMomentumRatioSRS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioSRS->SetLineColor(kBlue);
PionAngleRatioSRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioSRS->GetXaxis()->CenterTitle();
PionAngleRatioSRS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioNSRS->SetLineColor(kBlue);
PionEnergyRatioNSRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioNSRS->GetXaxis()->CenterTitle();
PionEnergyRatioNSRS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioNSRS->SetLineColor(kBlue);
PionMomentumRatioNSRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioNSRS->GetXaxis()->CenterTitle();
PionMomentumRatioNSRS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioNSRS->SetLineColor(kBlue);
PionAngleRatioNSRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioNSRS->GetXaxis()->CenterTitle();
PionAngleRatioNSRS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPRS->SetLineColor(kBlue);
RatioPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRS->GetXaxis()->CenterTitle();
RatioPRS->GetYaxis()->SetTitle("Efficiency");
RatioPRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCRS->SetLineColor(kBlue);
RatioCRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCRS->GetXaxis()->CenterTitle();
RatioCRS->GetYaxis()->SetTitle("Efficiency");
RatioCRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSPRS->SetLineColor(kRed);
RatioSPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioSPRS->GetXaxis()->CenterTitle();
RatioSPRS->GetYaxis()->SetTitle("Efficiency");
RatioSPRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSCRS->SetLineColor(kRed);
RatioSCRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioSCRS->GetXaxis()->CenterTitle();
RatioSCRS->GetYaxis()->SetTitle("Efficiency");
RatioSCRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSPRS->SetLineColor(kBlue);
RatioNSPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioNSPRS->GetXaxis()->CenterTitle();
RatioNSPRS->GetYaxis()->SetTitle("Efficiency");
RatioNSPRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSCRS->SetLineColor(kBlue);
RatioNSCRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioNSCRS->GetXaxis()->CenterTitle();
RatioNSCRS->GetYaxis()->SetTitle("Efficiency");
RatioNSCRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPRSCC->SetLineColor(kBlue);
RatioPRSCC->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRSCC->GetXaxis()->CenterTitle();
RatioPRSCC->GetYaxis()->SetTitle("Efficiency");
RatioPRSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCRSCC->SetLineColor(kBlue);
RatioCRSCC->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCRSCC->GetXaxis()->CenterTitle();
RatioCRSCC->GetYaxis()->SetTitle("Efficiency");
RatioCRSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
Ratio2DRS->GetYaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
Ratio2DRS->GetYaxis()->CenterTitle();
Ratio2DRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
Ratio2DRS->GetXaxis()->CenterTitle();


RatioPRS->Divide(hTotalGoodPNewRS, hTotalPNewRS);
RatioCRS->Divide(hTotalGoodCosNewRS, hTotalCosNewRS);
RatioSPRS->Divide(hGoodStoppedPNewRS, hTotalPNewRS);
RatioSCRS->Divide(hGoodStoppedCosNewRS, hTotalCosNewRS);
RatioNSPRS->Divide(hGoodNonStoppedPNewRS, hTotalPNewRS);
RatioNSCRS->Divide(hGoodNonStoppedCosNewRS, hTotalCosNewRS);
RatioPRSCC->Divide(hTotalGoodPNewRSCC, hTotalPNewRSCC);
RatioCRSCC->Divide(hTotalGoodCosNewRSCC, hTotalCosNewRSCC);
PionEnergyRatioRS->Divide(hPionEnergyGoodRS, hPionEnergyRS);
PionMomentumRatioRS->Divide(hPionMomentumGoodRS, hPionMomentumRS);
PionAngleRatioRS->Divide(hPionAngleGoodRS, hPionAngleRS);
PionEnergyRatioSRS->Divide(hPionEnergyStoppedRS, hPionEnergyGoodRS);
PionMomentumRatioSRS->Divide(hPionMomentumStoppedRS, hPionMomentumGoodRS);
PionAngleRatioSRS->Divide(hPionAngleStoppedRS, hPionAngleGoodRS);
PionEnergyRatioNSRS->Divide(hPionEnergyNonStoppedRS, hPionEnergyGoodRS);
PionMomentumRatioNSRS->Divide(hPionMomentumNonStoppedRS, hPionMomentumGoodRS);
PionAngleRatioNSRS->Divide(hPionAngleNonStoppedRS, hPionAngleGoodRS);
Ratio2DRS->Divide(hGoodRatioRS, hTotalRatioRS);




// ##############################################
// # Drawing the Momentum Efficiency Histograms #
// ##############################################

TCanvas *c1 = new TCanvas("c1", "Muon Momentums Efficiencies Histogram");
c1->SetTicks();
c1->SetFillColor(kWhite);

RatioPBS->Draw("E1");
RatioPRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("SciBooNE MC");
leg->AddEntry(RatioPRS,"R-S Model");
leg->AddEntry(RatioPBS,"B-S Model"); 
leg->Draw();




// ############################################
// # Drawing the Angles Efficiency Histograms #
// ############################################

TCanvas *c6 = new TCanvas("c6", "Muon Angles Efficiencies Histogram");
c6->SetTicks();
c6->SetFillColor(kWhite);

RatioCBS->Draw("E1");
RatioCRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg5 = new TLegend();
leg5 = new TLegend(0.58,0.65,0.88,0.88);
leg5->SetTextSize(0.04);
leg5->SetTextAlign(12);
leg5->SetFillColor(kWhite);
leg5->SetLineColor(kWhite);
leg5->SetShadowColor(kWhite);
leg5->SetHeader("SciBooNE MC");
leg5->AddEntry(RatioCRS,"R-S Model");
leg5->AddEntry(RatioCBS,"B-S Model");
leg5->Draw();




// #################################################
// # Drawing the CC Momentum Efficiency Histograms #
// #################################################

TCanvas *c11 = new TCanvas("c11", "CC Muon Momentums Efficiencies Histogram");
c11->SetTicks();
c11->SetFillColor(kWhite);

RatioPBSCC->Draw("E1");
RatioPRSCC->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg10 = new TLegend();
leg10 = new TLegend(0.58,0.65,0.88,0.88);
leg10->SetTextSize(0.04);
leg10->SetTextAlign(12);
leg10->SetFillColor(kWhite);
leg10->SetLineColor(kWhite);
leg10->SetShadowColor(kWhite);
leg10->SetHeader("SciBooNE MC");
leg10->AddEntry(RatioPRSCC,"New R-S Model");
leg10->AddEntry(RatioPBSCC,"New B-S Model");
leg10->Draw();




// ###############################################
// # Drawing the CC Angles Efficiency Histograms #
// ###############################################

TCanvas *c12 = new TCanvas("c12", "CC Muon Angles Efficiencies Histogram");
c12->SetTicks();
c12->SetFillColor(kWhite);

RatioCBSCC->Draw("E1");
RatioCRSCC->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg11 = new TLegend();
leg11 = new TLegend(0.58,0.65,0.88,0.88);
leg11->SetTextSize(0.04);
leg11->SetTextAlign(12);
leg11->SetFillColor(kWhite);
leg11->SetLineColor(kWhite);
leg11->SetShadowColor(kWhite);
leg11->SetHeader("SciBooNE MC");
leg11->AddEntry(RatioCRSCC,"New R-S Model");
leg11->AddEntry(RatioCBSCC,"New B-S Model");
leg11->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c2 = new TCanvas("c2", "Muon Momentums");
c2->SetTicks();
c2->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalPNewRS->Scale(1/hTotalPNewRS->Integral());
hTotalPNewBS->Scale(1/hTotalPNewBS->Integral());

hTotalPNewRS->SetLineColor(kBlue);
hTotalPNewRS->SetLineWidth(2);

hTotalPNewBS->SetLineColor(kRed);
hTotalPNewBS->SetLineWidth(2);

hTotalPNewBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hTotalPNewBS->GetXaxis()->CenterTitle();

hTotalPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hTotalPNewBS->GetYaxis()->CenterTitle();

hTotalPNewBS->Draw("histo");
hTotalPNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg1 = new TLegend();
leg1 = new TLegend(0.58,0.65,0.88,0.88);
leg1->SetTextSize(0.04);
leg1->SetTextAlign(12);
leg1->SetFillColor(kWhite);
leg1->SetLineColor(kWhite);
leg1->SetShadowColor(kWhite);
leg1->SetHeader("SciBooNE MC");
leg1->AddEntry(hTotalPNewRS,"R-S Model");
leg1->AddEntry(hTotalPNewBS,"B-S Model"); 
leg1->Draw();



// #################################
// # Drawing the Cosine Histograms #
// #################################

TCanvas *c3 = new TCanvas("c3", "Muon Angles");
c3->SetTicks();
c3->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalCosNewRS->Scale(1/hTotalCosNewRS->Integral());
hTotalCosNewBS->Scale(1/hTotalCosNewBS->Integral());

hTotalCosNewRS->SetLineColor(kBlue);
hTotalCosNewRS->SetLineWidth(2);

hTotalCosNewBS->SetLineColor(kRed);
hTotalCosNewBS->SetLineWidth(2);

hTotalCosNewBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hTotalCosNewBS->GetXaxis()->CenterTitle();

hTotalCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hTotalCosNewBS->GetYaxis()->CenterTitle();

hTotalCosNewBS->Draw("histo");
hTotalCosNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg2 = new TLegend();
leg2 = new TLegend(0.58,0.65,0.88,0.88);
leg2->SetTextSize(0.04);
leg2->SetTextAlign(12);
leg2->SetFillColor(kWhite);
leg2->SetLineColor(kWhite);
leg2->SetShadowColor(kWhite);
leg2->SetHeader("SciBooNE MC");
leg2->AddEntry(hTotalCosNewRS,"R-S Model");
leg2->AddEntry(hTotalCosNewBS,"B-S Model");
leg2->Draw();



// ########################################
// # Drawing the Good Momentum Histograms #
// ########################################

TCanvas *c4 = new TCanvas("c4", "Good Muon Momentums");
c4->SetTicks();
c4->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalGoodPNewRS->Scale(1/hTotalGoodPNewRS->Integral());
hTotalGoodPNewBS->Scale(1/hTotalGoodPNewBS->Integral());

hTotalGoodPNewRS->SetLineColor(kBlue);
hTotalGoodPNewRS->SetLineWidth(2);

hTotalGoodPNewBS->SetLineColor(kRed);
hTotalGoodPNewBS->SetLineWidth(2);

hTotalGoodPNewBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hTotalGoodPNewBS->GetXaxis()->CenterTitle();

hTotalGoodPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hTotalGoodPNewBS->GetYaxis()->CenterTitle();

hTotalGoodPNewBS->Draw("histo");
hTotalGoodPNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg3 = new TLegend();
leg3 = new TLegend(0.58,0.65,0.88,0.88);
leg3->SetTextSize(0.04);
leg3->SetTextAlign(12);
leg3->SetFillColor(kWhite);
leg3->SetLineColor(kWhite);
leg3->SetShadowColor(kWhite);
leg3->SetHeader("SciBooNE MC");
leg3->AddEntry(hTotalGoodPNewRS,"R-S Model");
leg3->AddEntry(hTotalGoodPNewBS,"B-S Model");
leg3->Draw();



// ######################################
// # Drawing the Good Cosine Histograms #
// ######################################

TCanvas *c5 = new TCanvas("c5", "Good Muon Angles");
c5->SetTicks();
c5->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalGoodCosNewRS->Scale(1/hTotalGoodCosNewRS->Integral());
hTotalGoodCosNewBS->Scale(1/hTotalGoodCosNewBS->Integral());

hTotalGoodCosNewRS->SetLineColor(kBlue);
hTotalGoodCosNewRS->SetLineWidth(2);

hTotalGoodCosNewBS->SetLineColor(kRed);
hTotalGoodCosNewBS->SetLineWidth(2);

hTotalGoodCosNewBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hTotalGoodCosNewBS->GetXaxis()->CenterTitle();

hTotalGoodCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hTotalGoodCosNewBS->GetYaxis()->CenterTitle();

hTotalGoodCosNewBS->Draw("histo");
hTotalGoodCosNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg4 = new TLegend();
leg4 = new TLegend(0.58,0.65,0.88,0.88);
leg4->SetTextSize(0.04);
leg4->SetTextAlign(12);
leg4->SetFillColor(kWhite);
leg4->SetLineColor(kWhite);
leg4->SetShadowColor(kWhite);
leg4->SetHeader("SciBooNE MC");
leg4->AddEntry(hTotalGoodCosNewRS,"R-S Model");
leg4->AddEntry(hTotalGoodCosNewBS,"B-S Model");
leg4->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c10 = new TCanvas("c10", "Muon Momentums");
c10->SetTicks();
c10->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodStoppedPNewRS->Scale(1/hGoodStoppedPNewRS->Integral());
hGoodStoppedPNewBS->Scale(1/hGoodStoppedPNewBS->Integral());

hGoodStoppedPNewRS->SetLineColor(kBlue);
hGoodStoppedPNewRS->SetLineWidth(2);

hGoodStoppedPNewBS->SetLineColor(kRed);
hGoodStoppedPNewBS->SetLineWidth(2);

hGoodStoppedPNewBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hGoodStoppedPNewBS->GetXaxis()->CenterTitle();

hGoodStoppedPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hGoodStoppedPNewBS->GetYaxis()->CenterTitle();

hGoodStoppedPNewBS->Draw("histo");
hGoodStoppedPNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg9 = new TLegend();
leg9 = new TLegend(0.58,0.65,0.88,0.88);
leg9->SetTextSize(0.04);
leg9->SetTextAlign(12);
leg9->SetFillColor(kWhite);
leg9->SetLineColor(kWhite);
leg9->SetShadowColor(kWhite);
leg9->SetHeader("SciBooNE MC");
leg9->AddEntry(hGoodStoppedPNewRS,"New R-S Model");
leg9->AddEntry(hGoodStoppedPNewBS,"New B-S Model");
leg9->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c7 = new TCanvas("c7", "Muon Momentums");
c7->SetTicks();
c7->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodNonStoppedPNewRS->Scale(1/hGoodNonStoppedPNewRS->Integral());
hGoodNonStoppedPNewBS->Scale(1/hGoodNonStoppedPNewBS->Integral());

hGoodNonStoppedPNewRS->SetLineColor(kBlue);
hGoodNonStoppedPNewRS->SetLineWidth(2);

hGoodNonStoppedPNewBS->SetLineColor(kRed);
hGoodNonStoppedPNewBS->SetLineWidth(2);

hGoodNonStoppedPNewBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hGoodNonStoppedPNewBS->GetXaxis()->CenterTitle();

hGoodNonStoppedPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hGoodNonStoppedPNewBS->GetYaxis()->CenterTitle();

hGoodNonStoppedPNewBS->Draw("histo");
hGoodNonStoppedPNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg6 = new TLegend();
leg6 = new TLegend(0.58,0.65,0.88,0.88);
leg6->SetTextSize(0.04);
leg6->SetTextAlign(12);
leg6->SetFillColor(kWhite);
leg6->SetLineColor(kWhite);
leg6->SetShadowColor(kWhite);
leg6->SetHeader("SciBooNE MC");
leg6->AddEntry(hGoodNonStoppedPNewRS,"New R-S Model");
leg6->AddEntry(hGoodNonStoppedPNewBS,"New B-S Model");
leg6->Draw();




// ###################################
// # Drawing the Angle Histograms #
// ###################################

TCanvas *c8 = new TCanvas("c8", "Muon Angles");
c8->SetTicks();
c8->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodNonStoppedCosNewRS->Scale(1/hGoodNonStoppedCosNewRS->Integral());
hGoodNonStoppedCosNewBS->Scale(1/hGoodNonStoppedCosNewBS->Integral());

hGoodNonStoppedCosNewRS->SetLineColor(kBlue);
hGoodNonStoppedCosNewRS->SetLineWidth(2);

hGoodNonStoppedCosNewBS->SetLineColor(kRed);
hGoodNonStoppedCosNewBS->SetLineWidth(2);

hGoodNonStoppedCosNewBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hGoodNonStoppedCosNewBS->GetXaxis()->CenterTitle();

hGoodNonStoppedCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hGoodNonStoppedCosNewBS->GetYaxis()->CenterTitle();

hGoodNonStoppedCosNewBS->Draw("histo");
hGoodNonStoppedCosNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg7 = new TLegend();
leg7 = new TLegend(0.58,0.65,0.88,0.88);
leg7->SetTextSize(0.04);
leg7->SetTextAlign(12);
leg7->SetFillColor(kWhite);
leg7->SetLineColor(kWhite);
leg7->SetShadowColor(kWhite);
leg7->SetHeader("SciBooNE MC");
leg7->AddEntry(hGoodNonStoppedCosNewRS,"New R-S Model");
leg7->AddEntry(hGoodNonStoppedCosNewBS,"New B-S Model");
leg7->Draw();




// ###################################
// # Drawing the Angle Histograms #
// ###################################

TCanvas *c9 = new TCanvas("c9", "Muon Angles");
c9->SetTicks();
c9->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodStoppedCosNewRS->Scale(1/hGoodStoppedCosNewRS->Integral());
hGoodStoppedCosNewBS->Scale(1/hGoodStoppedCosNewBS->Integral());

hGoodStoppedCosNewRS->SetLineColor(kBlue);
hGoodStoppedCosNewRS->SetLineWidth(2);

hGoodStoppedCosNewBS->SetLineColor(kRed);
hGoodStoppedCosNewBS->SetLineWidth(2);

hGoodStoppedCosNewBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hGoodStoppedCosNewBS->GetXaxis()->CenterTitle();

hGoodStoppedCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hGoodStoppedCosNewBS->GetYaxis()->CenterTitle();

hGoodStoppedCosNewBS->Draw("histo");
hGoodStoppedCosNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg8 = new TLegend();
leg8 = new TLegend(0.58,0.65,0.88,0.88);
leg8->SetTextSize(0.04);
leg8->SetTextAlign(12);
leg8->SetFillColor(kWhite);
leg8->SetLineColor(kWhite);
leg8->SetShadowColor(kWhite);
leg8->SetHeader("SciBooNE MC");
leg8->AddEntry(hGoodStoppedCosNewRS,"New R-S Model");
leg8->AddEntry(hGoodStoppedCosNewBS,"New B-S Model");
leg8->Draw();




// ###########################################
// # Drawing the 2D RS Efficiency Histograms #
// ###########################################

TCanvas *c17 = new TCanvas("c17", "2D R-S Muon Efficiency Histogram");
c17->SetTicks();
c17->SetFillColor(kWhite);

Ratio2DRS->Draw("colz");




// ###########################################
// # Drawing the 2D BS Efficiency Histograms #
// ###########################################

TCanvas *c18 = new TCanvas("c18", "2D B-S Muon Efficiency Histogram");
c18->SetTicks();
c18->SetFillColor(kWhite);

Ratio2DBS->Draw("colz");




// ############################################
// # Drawing Berger-Sehgal Mom and Cos Ratios #
// ############################################

TCanvas *c20 = new TCanvas("c20", "Berger-Sehgal Momentum Ratios for Non-Stopped and Stopped");
c20->SetTicks();
c20->SetFillColor(kWhite);

RatioNSPBS->Draw("histo");
RatioSPBS->Draw("histosame");


TCanvas *c21 = new TCanvas("c21", "Berger-Sehgal Angle Ratios for Non-Stopped and Stopped");
c21->SetTicks();
c21->SetFillColor(kWhite);

RatioSCBS->Draw("histo");
RatioNSCBS->Draw("histosame");




// ##########################################
// # Drawing Rein-Sehgal Mom and Cos Ratios #
// ##########################################

TCanvas *c22 = new TCanvas("c22", "Rein-Sehgal Momentum Ratios for Non-Stopped and Stopped");
c22->SetTicks();
c22->SetFillColor(kWhite);

RatioNSPRS->Draw("histo");
RatioSPRS->Draw("histosame");


TCanvas *c23 = new TCanvas("c23", "Rein-Sehgal Angle Ratios for Non-Stopped and Stopped");
c23->SetTicks();
c23->SetFillColor(kWhite);

RatioSCRS->Draw("histo");
RatioNSCRS->Draw("histosame");




// #####################################################
// # Drawing the Good Pion Energy Efficiency Histogram #
// #####################################################

TCanvas *c26 = new TCanvas("c26", "Pion Good Energy Efficiencies Histogram");
c26->SetTicks();
c26->SetFillColor(kWhite);

PionEnergyRatioBS->Draw("E1");
PionEnergyRatioRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg16 = new TLegend();
leg16 = new TLegend(0.58,0.65,0.88,0.88);
leg16->SetTextSize(0.04);
leg16->SetTextAlign(12);
leg16->SetFillColor(kWhite);
leg16->SetLineColor(kWhite);
leg16->SetShadowColor(kWhite);
leg16->SetHeader("SciBooNE MC");
leg16->AddEntry(PionEnergyRatioRS,"New R-S Model");
leg16->AddEntry(PionEnergyRatioBS,"New B-S Model");
leg16->Draw();




// #######################################################
// # Drawing the Good Pion Momentum Efficiency Histogram #
// #######################################################

TCanvas *c27 = new TCanvas("c27", "Pion Good Momentum Efficiencies Histogram");
c27->SetTicks();
c27->SetFillColor(kWhite);

PionMomentumRatioBS->Draw("E1");
PionMomentumRatioRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg17 = new TLegend();
leg17 = new TLegend(0.58,0.65,0.88,0.88);
leg17->SetTextSize(0.04);
leg17->SetTextAlign(12);
leg17->SetFillColor(kWhite);
leg17->SetLineColor(kWhite);
leg17->SetShadowColor(kWhite);
leg17->SetHeader("SciBooNE MC");
leg17->AddEntry(PionMomentumRatioRS,"New R-S Model");
leg17->AddEntry(PionMomentumRatioBS,"New B-S Model");
leg17->Draw();




// #######################################################
// # Drawing the Good Pion Angles Efficiency Histogram #
// #######################################################

TCanvas *c28 = new TCanvas("c28", "Pion Good Angle Efficiencies Histogram");
c28->SetTicks();
c28->SetFillColor(kWhite);

PionAngleRatioBS->Draw("E1");
PionAngleRatioRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg18 = new TLegend();
leg18 = new TLegend(0.58,0.65,0.88,0.88);
leg18->SetTextSize(0.04);
leg18->SetTextAlign(12);
leg18->SetFillColor(kWhite);
leg18->SetLineColor(kWhite);
leg18->SetShadowColor(kWhite);
leg18->SetHeader("SciBooNE MC");
leg18->AddEntry(PionAngleRatioRS,"New R-S Model");
leg18->AddEntry(PionAngleRatioBS,"New B-S Model");
leg18->Draw();




// ########################################################
// # Drawing the Stopped Pion Energy Efficiency Histogram #
// ########################################################

TCanvas *c29 = new TCanvas("c29", "Pion Stopped Energy Efficiencies Histogram");
c29->SetTicks();
c29->SetFillColor(kWhite);

PionEnergyRatioSBS->Draw("E1");
PionEnergyRatioSRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg19 = new TLegend();
leg19 = new TLegend(0.58,0.65,0.88,0.88);
leg19->SetTextSize(0.04);
leg19->SetTextAlign(12);
leg19->SetFillColor(kWhite);
leg19->SetLineColor(kWhite);
leg19->SetShadowColor(kWhite);
leg19->SetHeader("SciBooNE MC");
leg19->AddEntry(PionEnergyRatioSRS,"New R-S Model");
leg19->AddEntry(PionEnergyRatioSBS,"New B-S Model");
leg19->Draw();




// ##########################################################
// # Drawing the Stopped Pion Momentum Efficiency Histogram #
// ##########################################################

TCanvas *c30 = new TCanvas("c30", "Pion Stopped Momentum Efficiencies Histogram");
c30->SetTicks();
c30->SetFillColor(kWhite);

PionMomentumRatioSBS->Draw("E1");
PionMomentumRatioSRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg20 = new TLegend();
leg20 = new TLegend(0.58,0.65,0.88,0.88);
leg20->SetTextSize(0.04);
leg20->SetTextAlign(12);
leg20->SetFillColor(kWhite);
leg20->SetLineColor(kWhite);
leg20->SetShadowColor(kWhite);
leg20->SetHeader("SciBooNE MC");
leg20->AddEntry(PionMomentumRatioSRS,"New R-S Model");
leg20->AddEntry(PionMomentumRatioSBS,"New B-S Model");
leg20->Draw();




// ########################################################
// # Drawing the Stopped Pion Angles Efficiency Histogram #
// ########################################################

TCanvas *c31 = new TCanvas("c31", "Pion Stopped Angle Efficiencies Histogram");
c31->SetTicks();
c31->SetFillColor(kWhite);

PionAngleRatioSBS->Draw("E1");
PionAngleRatioSRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg21 = new TLegend();
leg21 = new TLegend(0.58,0.65,0.88,0.88);
leg21->SetTextSize(0.04);
leg21->SetTextAlign(12);
leg21->SetFillColor(kWhite);
leg21->SetLineColor(kWhite);
leg21->SetShadowColor(kWhite);
leg21->SetHeader("SciBooNE MC");
leg21->AddEntry(PionAngleRatioSRS,"New R-S Model");
leg21->AddEntry(PionAngleRatioSBS,"New B-S Model");
leg21->Draw();




// ############################################################
// # Drawing the Non-Stopped Pion Energy Efficiency Histogram #
// ############################################################

TCanvas *c32 = new TCanvas("c32", "Pion Non-Stopped Energy Efficiencies Histogram");
c32->SetTicks();
c32->SetFillColor(kWhite);

PionEnergyRatioNSBS->Draw("E1");
PionEnergyRatioNSRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg22 = new TLegend();
leg22 = new TLegend(0.58,0.65,0.88,0.88);
leg22->SetTextSize(0.04);
leg22->SetTextAlign(12);
leg22->SetFillColor(kWhite);
leg22->SetLineColor(kWhite);
leg22->SetShadowColor(kWhite);
leg22->SetHeader("SciBooNE MC");
leg22->AddEntry(PionEnergyRatioNSRS,"New R-S Model");
leg22->AddEntry(PionEnergyRatioNSBS,"New B-S Model");
leg22->Draw();




// ##############################################################
// # Drawing the Non-Stopped Pion Momentum Efficiency Histogram #
// ##############################################################

TCanvas *c33 = new TCanvas("c33", "Pion Non-Stopped Momentum Efficiencies Histogram");
c33->SetTicks();
c33->SetFillColor(kWhite);

PionMomentumRatioNSBS->Draw("E1");
PionMomentumRatioNSRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg23 = new TLegend();
leg23 = new TLegend(0.58,0.65,0.88,0.88);
leg23->SetTextSize(0.04);
leg23->SetTextAlign(12);
leg23->SetFillColor(kWhite);
leg23->SetLineColor(kWhite);
leg23->SetShadowColor(kWhite);
leg23->SetHeader("SciBooNE MC");
leg23->AddEntry(PionMomentumRatioNSRS,"New R-S Model");
leg23->AddEntry(PionMomentumRatioNSBS,"New B-S Model");
leg23->Draw();




// ############################################################
// # Drawing the Non-Stopped Pion Angles Efficiency Histogram #
// ############################################################

TCanvas *c34 = new TCanvas("c34", "Pion Non-Stopped Angle Efficiencies Histogram");
c34->SetTicks();
c34->SetFillColor(kWhite);

PionAngleRatioNSBS->Draw("E1");
PionAngleRatioNSRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg24 = new TLegend();
leg24 = new TLegend(0.58,0.65,0.88,0.88);
leg24->SetTextSize(0.04);
leg24->SetTextAlign(12);
leg24->SetFillColor(kWhite);
leg24->SetLineColor(kWhite);
leg24->SetShadowColor(kWhite);
leg24->SetHeader("SciBooNE MC");
leg24->AddEntry(PionAngleRatioNSRS,"New R-S Model");
leg24->AddEntry(PionAngleRatioNSBS,"New B-S Model");
leg24->Draw();




// =================================================================================================================
//                              Accessing the bin information from the histograms
// =================================================================================================================
/*
for (int i=1; i<41; i++) {
   for (int j=1; j<41; j++) {
      Int_t bin = Ratio2DRS->GetBin(j,i,1);
      Double_t binContent = Ratio2DBS->GetBinContent(bin);
      //std::cout<<j<<", "<<i<<", "<<bin<<", "<<binContent<<std::endl;
      //std::cout<<j<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<bin<<std::endl;
      std::cout<<binContent<<std::endl;
      }


   }
*/
// =================================================================================================================


}
