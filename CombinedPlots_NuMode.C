{
// ####################
// # Read in the Data #
// ####################

// =======================================================================================
//                     ### Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBS.root"); //Load Total Muon Info File

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

// ### Defining the ratio histogram ###
TH1D *RatioPBS = new TH1D("RatioPBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCBS = new TH1D("RatioCBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPBSCC = new TH1D("RatioPBSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCBSCC = new TH1D("RatioCBSCC", "Efficiencies for Angles", 40, 0, 180);

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


RatioPBS->Divide(hTotalGoodPNewBS, hTotalPNewBS);
RatioCBS->Divide(hTotalGoodCosNewBS, hTotalCosNewBS);
RatioPBSCC->Divide(hTotalGoodPNewBSCC, hTotalPNewBSCC);
RatioCBSCC->Divide(hTotalGoodCosNewBSCC, hTotalCosNewBSCC);




// =======================================================================================
//                    ### Rein Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f2 = new TFile("./ROOTFILES/totalmuoninfoRS.root"); //Load Total Muon Info File

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

// ### Defining the ratio histogram ###
TH1D *RatioPRS = new TH1D("RatioPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRS = new TH1D("RatioCRS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPRSCC = new TH1D("RatioPRSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRSCC = new TH1D("RatioCRSCC", "Efficiencies for Angles", 40, 0, 180);
TH2D *Ratio2DRS = new TH2D("Ratio2DRS", "2D Efficiencies", 40, 0, 180, 40, 0, 2000);

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
RatioPRSCC->Divide(hTotalGoodPNewRSCC, hTotalPNewRSCC);
RatioCRSCC->Divide(hTotalGoodCosNewRSCC, hTotalCosNewRSCC);
Ratio2DRS->Divide(hGoodRatioRS, hTotalRatioRS);




// =======================================================================================
//                  ### Old Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f3 = new TFile("./ROOTFILES/totalmuoninfoOBS.root"); //Load Total Muon Info File

TH1D *hTotalPNewOBS = (TH1D*)f3->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewOBS = (TH1D*)f3->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewOBS = (TH1D*)f3->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewOBS = (TH1D*)f3->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hGoodStoppedPNewOBS = (TH1D*)f3->Get("GMuonMomS_1"); //Make a clone of the h6 histogram from the BergerSegal.C file for the good stopped muon momentum
TH1D *hGoodStoppedCosNewOBS = (TH1D*)f3->Get("GMuonCosS_1"); //Make a clone of the h8 histogram from the BergerSegal.C file for the good stopped muon angle

TH1D *hGoodNonStoppedPNewOBS = (TH1D*)f3->Get("GMuonMomNS_1"); //Make a clone of the h9 histogram from the BergerSegal.C file for the good nonstopped muon momentum
TH1D *hGoodNonStoppedCosNewOBS = (TH1D*)f3->Get("GMuonCosNS_1"); //Make a clone of the h10 histogram from the BergerSegal.C file for the good nonstopped muon angle

TH1D *hTotalPNewOBSCC = (TH1D*)f3->Get("CCTMuonMom_1"); //Make a clone of the h13 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewOBSCC = (TH1D*)f3->Get("CCTGMuonMom_1"); //Make a clone of the h19 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewOBSCC = (TH1D*)f3->Get("CCTMuonCos_1"); //Make a clone of the h14 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewOBSCC = (TH1D*)f3->Get("CCTGMuonCos_1"); //Make a clone of the h20 histogram from the NeutrinoMode.C file for total good muon angle


hTotalPNewOBS->Sumw2();
hTotalGoodPNewOBS->Sumw2();
hTotalCosNewOBS->Sumw2();
hTotalGoodCosNewOBS->Sumw2();
hGoodStoppedPNewOBS->Sumw2();
hGoodStoppedCosNewOBS->Sumw2();
hGoodNonStoppedPNewOBS->Sumw2();
hGoodNonStoppedCosNewOBS->Sumw2();
hTotalPNewOBSCC->Sumw2();
hTotalGoodPNewOBSCC->Sumw2();
hTotalCosNewOBSCC->Sumw2();
hTotalGoodCosNewOBSCC->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPOBS = new TH1D("RatioPOBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCOBS = new TH1D("RatioCOBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPOBSCC = new TH1D("RatioPOBSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCOBSCC = new TH1D("RatioCOBSCC", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPOBS->SetLineColor(kBlack);
RatioPOBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPOBS->GetXaxis()->CenterTitle();
RatioPOBS->GetYaxis()->SetTitle("Efficiency");
RatioPOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCOBS->SetLineColor(kBlack);
RatioCOBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCOBS->GetXaxis()->CenterTitle();
RatioCOBS->GetYaxis()->SetTitle("Efficiency");
RatioCOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPOBSCC->SetLineColor(kBlack);
RatioPOBSCC->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPOBSCC->GetXaxis()->CenterTitle();
RatioPOBSCC->GetYaxis()->SetTitle("Efficiency");
RatioPOBSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCOBSCC->SetLineColor(kBlack);
RatioCOBSCC->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCOBSCC->GetXaxis()->CenterTitle();
RatioCOBSCC->GetYaxis()->SetTitle("Efficiency");
RatioCOBSCC->GetYaxis()->CenterTitle();


RatioPOBS->Divide(hTotalGoodPNewOBS, hTotalPNewOBS);
RatioCOBS->Divide(hTotalGoodCosNewOBS, hTotalCosNewOBS);
RatioPOBSCC->Divide(hTotalGoodPNewOBSCC, hTotalPNewOBSCC);
RatioCOBSCC->Divide(hTotalGoodCosNewOBSCC, hTotalCosNewOBSCC);




// =======================================================================================
//                ### Berger Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f4 = new TFile("./ROOTFILES/totalmuoninfoBSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewBSBar = (TH1D*)f4->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewBSBar = (TH1D*)f4->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewBSBar = (TH1D*)f4->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewBSBar = (TH1D*)f4->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle


hTotalPNewBSBar->Sumw2();
hTotalGoodPNewBSBar->Sumw2();
hTotalCosNewBSBar->Sumw2();
hTotalGoodCosNewBSBar->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPBSBar = new TH1D("RatioPBSBar", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCBSBar = new TH1D("RatioCBSBar", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPBSBar->SetLineColor(kBlack);
RatioPBSBar->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBSBar->GetXaxis()->CenterTitle();
RatioPBSBar->GetYaxis()->SetTitle("Efficiency");
RatioPBSBar->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCBSBar->SetLineColor(kBlack);
RatioCBSBar->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCBSBar->GetXaxis()->CenterTitle();
RatioCBSBar->GetYaxis()->SetTitle("Efficiency");
RatioCBSBar->GetYaxis()->CenterTitle();

RatioPBSBar->Divide(hTotalGoodPNewBSBar, hTotalPNewBSBar);
RatioCBSBar->Divide(hTotalGoodCosNewBSBar, hTotalCosNewBSBar);




// =======================================================================================
//                ### Rein Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f5 = new TFile("./ROOTFILES/totalmuoninfoRSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewRSBar = (TH1D*)f5->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRSBar = (TH1D*)f5->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRSBar = (TH1D*)f5->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRSBar = (TH1D*)f5->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle


hTotalPNewRSBar->Sumw2();
hTotalGoodPNewRSBar->Sumw2();
hTotalCosNewRSBar->Sumw2();
hTotalGoodCosNewRSBar->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPRSBar = new TH1D("RatioPRSBar", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRSBar = new TH1D("RatioCRSBar", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPRSBar->SetLineColor(kMagenta);
RatioPRSBar->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRSBar->GetXaxis()->CenterTitle();
RatioPRSBar->GetYaxis()->SetTitle("Efficiency");
RatioPRSBar->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCRSBar->SetLineColor(kMagenta);
RatioCRSBar->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCRSBar->GetXaxis()->CenterTitle();
RatioCRSBar->GetYaxis()->SetTitle("Efficiency");
RatioCRSBar->GetYaxis()->CenterTitle();

RatioPRSBar->Divide(hTotalGoodPNewRSBar, hTotalPNewRSBar);
RatioCRSBar->Divide(hTotalGoodCosNewRSBar, hTotalCosNewRSBar);




// ##############################################
// # Drawing the Momentum Efficiency Histograms #
// ##############################################

TCanvas *c1 = new TCanvas("c1", "Muon Momentums Efficiencies Histogram");
c1->SetTicks();
c1->SetFillColor(kWhite);

RatioPBS->Draw("E1");
RatioPRS->Draw("E1same");
RatioPOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("SciBooNE MC");
leg->AddEntry(RatioPRS,"New R-S Model");
leg->AddEntry(RatioPBS,"New B-S Model");
leg->AddEntry(RatioPOBS, "Old B-S Model");
leg->Draw();




// ############################################
// # Drawing the Angles Efficiency Histograms #
// ############################################

TCanvas *c6 = new TCanvas("c6", "Muon Angles Efficiencies Histogram");
c6->SetTicks();
c6->SetFillColor(kWhite);

RatioCBS->Draw("E1");
RatioCRS->Draw("E1same");
RatioCOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg5 = new TLegend();
leg5 = new TLegend(0.58,0.65,0.88,0.88);
leg5->SetTextSize(0.04);
leg5->SetTextAlign(12);
leg5->SetFillColor(kWhite);
leg5->SetLineColor(kWhite);
leg5->SetShadowColor(kWhite);
leg5->SetHeader("SciBooNE MC");
leg5->AddEntry(RatioCRS,"New R-S Model");
leg5->AddEntry(RatioCBS,"New B-S Model");
leg5->AddEntry(RatioCOBS, "Old B-S Model");
leg5->Draw();




// #################################################
// # Drawing the CC Momentum Efficiency Histograms #
// #################################################

TCanvas *c11 = new TCanvas("c11", "CC Muon Momentums Efficiencies Histogram");
c11->SetTicks();
c11->SetFillColor(kWhite);

RatioPBSCC->Draw("E1");
RatioPRSCC->Draw("E1same");
RatioPOBSCC->Draw("E1same");

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
leg10->AddEntry(RatioPOBSCC, "Old B-S Model");
leg10->Draw();




// ###############################################
// # Drawing the CC Angles Efficiency Histograms #
// ###############################################

TCanvas *c12 = new TCanvas("c12", "CC Muon Angles Efficiencies Histogram");
c12->SetTicks();
c12->SetFillColor(kWhite);

RatioCBSCC->Draw("E1");
RatioCRSCC->Draw("E1same");
RatioCOBSCC->Draw("E1same");

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
leg11->AddEntry(RatioCOBSCC,"Old B-S Model");
leg11->Draw();




// ################################################################
// # Drawing the RS Neut-Anti-Neut Momentum Efficiency Histograms #
// ################################################################

TCanvas *c13 = new TCanvas("c13", "R-S Neut-Anti-Neut Muon Momentums Efficiencies Histogram");
c13->SetTicks();
c13->SetFillColor(kWhite);

RatioPRS->Draw("E1");
RatioPRSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg12 = new TLegend();
leg12 = new TLegend(0.58,0.65,0.88,0.88);
leg12->SetTextSize(0.04);
leg12->SetTextAlign(12);
leg12->SetFillColor(kWhite);
leg12->SetLineColor(kWhite);
leg12->SetShadowColor(kWhite);
leg12->SetHeader("SciBooNE MC");
leg12->AddEntry(RatioPRS,"Neut R-S Model");
leg12->AddEntry(RatioPRSBar,"Anti-Neut R-S Model");
leg12->Draw();




// ##############################################################
// # Drawing the RS Neut-Anti-Neut Angles Efficiency Histograms #
// ##############################################################

TCanvas *c14 = new TCanvas("c14", "R-S Neut-Anti-Neut Muon Angles Efficiencies Histogram");
c14->SetTicks();
c14->SetFillColor(kWhite);

RatioCRS->Draw("E1");
RatioCRSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg13 = new TLegend();
leg13 = new TLegend(0.58,0.65,0.88,0.88);
leg13->SetTextSize(0.04);
leg13->SetTextAlign(12);
leg13->SetFillColor(kWhite);
leg13->SetLineColor(kWhite);
leg13->SetShadowColor(kWhite);
leg13->SetHeader("SciBooNE MC");
leg13->AddEntry(RatioCRS,"Neut R-S Model");
leg13->AddEntry(RatioCRSBar,"Anti-Neut R-S Model");
leg13->Draw();



// ################################################################
// # Drawing the BS Neut-Anti-Neut Momentum Efficiency Histograms #
// ################################################################

TCanvas *c15 = new TCanvas("c15", "B-S Neut-Anti-Neut Muon Momentums Efficiencies Histogram");
c15->SetTicks();
c15->SetFillColor(kWhite);

RatioPBS->Draw("E1");
RatioPBSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg14 = new TLegend();
leg14 = new TLegend(0.58,0.65,0.88,0.88);
leg14->SetTextSize(0.04);
leg14->SetTextAlign(12);
leg14->SetFillColor(kWhite);
leg14->SetLineColor(kWhite);
leg14->SetShadowColor(kWhite);
leg14->SetHeader("SciBooNE MC");
leg14->AddEntry(RatioPBS,"Neut B-S Model");
leg14->AddEntry(RatioPBSBar,"Anti-Neut B-S Model");
leg14->Draw();




// ##############################################################
// # Drawing the BS Neut-Anti-Neut Angles Efficiency Histograms #
// ##############################################################

TCanvas *c16 = new TCanvas("c16", "B-S Neut-Anti-Neut Muon Angles Efficiencies Histogram");
c16->SetTicks();
c16->SetFillColor(kWhite);

RatioCBS->Draw("E1");
RatioCBSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg15 = new TLegend();
leg15 = new TLegend(0.58,0.65,0.88,0.88);
leg15->SetTextSize(0.04);
leg15->SetTextAlign(12);
leg15->SetFillColor(kWhite);
leg15->SetLineColor(kWhite);
leg15->SetShadowColor(kWhite);
leg15->SetHeader("SciBooNE MC");
leg15->AddEntry(RatioCBS,"Neut B-S Model");
leg15->AddEntry(RatioCBSBar,"Anti-Neut B-S Model");
leg15->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c2 = new TCanvas("c2", "Muon Momentums");
c2->SetTicks();
c2->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalPNewRS->Scale(1/hTotalPNewRS->Integral());

hTotalPNewBS->Scale(1/hTotalPNewBS->Integral());

hTotalPNewOBS->Scale(1/hTotalPNewOBS->Integral());

hTotalPNewRS->SetLineColor(kBlue);
hTotalPNewRS->SetLineWidth(2);

hTotalPNewBS->SetLineColor(kRed);
hTotalPNewBS->SetLineWidth(2);

hTotalPNewOBS->SetLineColor(kBlack);
hTotalPNewOBS->SetLineWidth(2);

hTotalPNewOBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hTotalPNewOBS->GetYaxis()->CenterTitle();

hTotalPNewOBS->Draw("histo");
hTotalPNewRS->Draw("histosame");
hTotalPNewBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg1 = new TLegend();
leg1 = new TLegend(0.58,0.65,0.88,0.88);
leg1->SetTextSize(0.04);
leg1->SetTextAlign(12);
leg1->SetFillColor(kWhite);
leg1->SetLineColor(kWhite);
leg1->SetShadowColor(kWhite);
leg1->SetHeader("SciBooNE MC");
leg1->AddEntry(hTotalPNewRS,"New R-S Model");
leg1->AddEntry(hTotalPNewBS,"New B-S Model");
leg1->AddEntry(hTotalPNewOBS,"Old B-S Model");
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

hTotalCosNewOBS->Scale(1/hTotalCosNewOBS->Integral());

hTotalCosNewRS->SetLineColor(kBlue);
hTotalCosNewRS->SetLineWidth(2);

hTotalCosNewBS->SetLineColor(kRed);
hTotalCosNewBS->SetLineWidth(2);

hTotalCosNewOBS->SetLineColor(kBlack);
hTotalCosNewOBS->SetLineWidth(2);

hTotalCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hTotalCosNewBS->GetYaxis()->CenterTitle();

hTotalCosNewBS->Draw("histo");
hTotalCosNewRS->Draw("histosame");
hTotalCosNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg2 = new TLegend();
leg2 = new TLegend(0.58,0.65,0.88,0.88);
leg2->SetTextSize(0.04);
leg2->SetTextAlign(12);
leg2->SetFillColor(kWhite);
leg2->SetLineColor(kWhite);
leg2->SetShadowColor(kWhite);
leg2->SetHeader("SciBooNE MC");
leg2->AddEntry(hTotalCosNewRS,"New R-S Model");
leg2->AddEntry(hTotalCosNewBS,"New B-S Model");
leg2->AddEntry(hTotalCosNewOBS, "Old B-S Model");
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

hTotalGoodPNewOBS->Scale(1/hTotalGoodPNewOBS->Integral());

hTotalGoodPNewRS->SetLineColor(kBlue);
hTotalGoodPNewRS->SetLineWidth(2);

hTotalGoodPNewBS->SetLineColor(kRed);
hTotalGoodPNewBS->SetLineWidth(2);

hTotalGoodPNewOBS->SetLineColor(kBlack);
hTotalGoodPNewOBS->SetLineWidth(2);

hTotalGoodPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hTotalGoodPNewBS->GetYaxis()->CenterTitle();

hTotalGoodPNewBS->Draw("histo");
hTotalGoodPNewRS->Draw("histosame");
hTotalGoodPNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg3 = new TLegend();
leg3 = new TLegend(0.58,0.65,0.88,0.88);
leg3->SetTextSize(0.04);
leg3->SetTextAlign(12);
leg3->SetFillColor(kWhite);
leg3->SetLineColor(kWhite);
leg3->SetShadowColor(kWhite);
leg3->SetHeader("SciBooNE MC");
leg3->AddEntry(hTotalGoodPNewRS,"New R-S Model");
leg3->AddEntry(hTotalGoodPNewBS,"New B-S Model");
leg3->AddEntry(hTotalGoodPNewOBS, "Old B-S Model");
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

hTotalGoodCosNewOBS->Scale(1/hTotalGoodCosNewOBS->Integral());

hTotalGoodCosNewRS->SetLineColor(kBlue);
hTotalGoodCosNewRS->SetLineWidth(2);

hTotalGoodCosNewBS->SetLineColor(kRed);
hTotalGoodCosNewBS->SetLineWidth(2);

hTotalGoodCosNewOBS->SetLineColor(kBlack);
hTotalGoodCosNewOBS->SetLineWidth(2);

hTotalGoodCosNewOBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hTotalGoodCosNewOBS->GetYaxis()->CenterTitle();

hTotalGoodCosNewOBS->Draw("histo");
hTotalGoodCosNewRS->Draw("histosame");
hTotalGoodCosNewBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg4 = new TLegend();
leg4 = new TLegend(0.58,0.65,0.88,0.88);
leg4->SetTextSize(0.04);
leg4->SetTextAlign(12);
leg4->SetFillColor(kWhite);
leg4->SetLineColor(kWhite);
leg4->SetShadowColor(kWhite);
leg4->SetHeader("SciBooNE MC");
leg4->AddEntry(hTotalGoodCosNewRS,"New R-S Model");
leg4->AddEntry(hTotalGoodCosNewBS,"New B-S Model");
leg4->AddEntry(hTotalGoodCosNewOBS, "Old B-S Model");
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

hGoodStoppedPNewOBS->Scale(1/hGoodStoppedPNewOBS->Integral());

hGoodStoppedPNewRS->SetLineColor(kBlue);
hGoodStoppedPNewRS->SetLineWidth(2);

hGoodStoppedPNewBS->SetLineColor(kRed);
hGoodStoppedPNewBS->SetLineWidth(2);

hGoodStoppedPNewOBS->SetLineColor(kBlack);
hGoodStoppedPNewOBS->SetLineWidth(2);

hGoodStoppedPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hGoodStoppedPNewBS->GetYaxis()->CenterTitle();

hGoodStoppedPNewBS->Draw("histo");
hGoodStoppedPNewRS->Draw("histosame");
hGoodStoppedPNewOBS->Draw("histosame");


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
leg9->AddEntry(hGoodStoppedPNewOBS,"Old B-S Model");
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

hGoodNonStoppedPNewOBS->Scale(1/hGoodNonStoppedPNewOBS->Integral());

hGoodNonStoppedPNewRS->SetLineColor(kBlue);
hGoodNonStoppedPNewRS->SetLineWidth(2);

hGoodNonStoppedPNewBS->SetLineColor(kRed);
hGoodNonStoppedPNewBS->SetLineWidth(2);

hGoodNonStoppedPNewOBS->SetLineColor(kBlack);
hGoodNonStoppedPNewOBS->SetLineWidth(2);

hGoodNonStoppedPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hGoodNonStoppedPNewBS->GetYaxis()->CenterTitle();

hGoodNonStoppedPNewBS->Draw("histo");
hGoodNonStoppedPNewRS->Draw("histosame");
hGoodNonStoppedPNewOBS->Draw("histosame");


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
leg6->AddEntry(hGoodNonStoppedPNewOBS,"Old B-S Model");
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

hGoodNonStoppedCosNewOBS->Scale(1/hGoodNonStoppedCosNewOBS->Integral());

hGoodNonStoppedCosNewRS->SetLineColor(kBlue);
hGoodNonStoppedCosNewRS->SetLineWidth(2);

hGoodNonStoppedCosNewBS->SetLineColor(kRed);
hGoodNonStoppedCosNewBS->SetLineWidth(2);

hGoodNonStoppedCosNewOBS->SetLineColor(kBlack);
hGoodNonStoppedCosNewOBS->SetLineWidth(2);

hGoodNonStoppedCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hGoodNonStoppedCosNewBS->GetYaxis()->CenterTitle();

hGoodNonStoppedCosNewBS->Draw("histo");
hGoodNonStoppedCosNewRS->Draw("histosame");
hGoodNonStoppedCosNewOBS->Draw("histosame");


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
leg7->AddEntry(hGoodNonStoppedCosNewOBS,"Old B-S Model");
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

hGoodStoppedCosNewOBS->Scale(1/hGoodStoppedCosNewOBS->Integral());

hGoodStoppedCosNewRS->SetLineColor(kBlue);
hGoodStoppedCosNewRS->SetLineWidth(2);

hGoodStoppedCosNewBS->SetLineColor(kRed);
hGoodStoppedCosNewBS->SetLineWidth(2);

hGoodStoppedCosNewOBS->SetLineColor(kBlack);
hGoodStoppedCosNewOBS->SetLineWidth(2);

hGoodStoppedCosNewOBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hGoodStoppedCosNewOBS->GetYaxis()->CenterTitle();

hGoodStoppedCosNewOBS->Draw("histo");
hGoodStoppedCosNewRS->Draw("histosame");
hGoodStoppedCosNewBS->Draw("histosame");


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
leg8->AddEntry(hGoodStoppedCosNewOBS,"Old B-S Model");
leg8->Draw();




// ###########################################
// # Drawing the 2D RS Efficiency Histograms #
// ###########################################

TCanvas *c17 = new TCanvas("c17", "2D R-S Muon Efficiency Histogram");
c17->SetTicks();
c17->SetFillColor(kWhite);

Ratio2DRS->Draw("colz");



}
