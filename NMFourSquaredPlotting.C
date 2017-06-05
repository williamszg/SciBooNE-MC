{
// ####################
// # Read in the Data #
// ####################


// =======================================================================================
//                     ### Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================

TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBS.root"); //Load Total Muon Info File

TH1D *hFourMomentumBothBS = (TH1D*)f1->Get("T4B");
TH1D *hFourMomentumStoppedBS = (TH1D*)f1->Get("T4S");
TH1D *hFourMomentumNonStoppedBS = (TH1D*)f1->Get("T4NS");

TH1D *hQSquaredBothBS = (TH1D*)f1->Get("Q2B");
TH1D *hQSquaredStoppedBS = (TH1D*)f1->Get("Q2S");
TH1D *hQSquaredNonStoppedBS = (TH1D*)f1->Get("Q2NS");


hFourMomentumBothBS->Sumw2();
hFourMomentumStoppedBS->Sumw2();
hFourMomentumNonStoppedBS->Sumw2();
hQSquaredBothBS->Sumw2();
hQSquaredStoppedBS->Sumw2();
hQSquaredNonStoppedBS->Sumw2();




// =======================================================================================
//                    ### Rein Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f2 = new TFile("./ROOTFILES/totalmuoninfoRS.root"); //Load Total Muon Info File

TH1D *hFourMomentumBothRS = (TH1D*)f2->Get("T4B");
TH1D *hFourMomentumStoppedRS = (TH1D*)f2->Get("T4S");
TH1D *hFourMomentumNonStoppedRS = (TH1D*)f2->Get("T4NS");

TH1D *hQSquaredBothRS = (TH1D*)f2->Get("Q2B");
TH1D *hQSquaredStoppedRS = (TH1D*)f2->Get("Q2S");
TH1D *hQSquaredNonStoppedRS = (TH1D*)f2->Get("Q2NS");


hFourMomentumBothRS->Sumw2();
hFourMomentumStoppedRS->Sumw2();
hFourMomentumNonStoppedRS->Sumw2();
hQSquaredBothRS->Sumw2();
hQSquaredStoppedRS->Sumw2();
hQSquaredNonStoppedRS->Sumw2();




// =======================================================================================
//                  ### Old Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f3 = new TFile("./ROOTFILES/totalmuoninfoOBS.root"); //Load Total Muon Info File

TH1D *hFourMomentumBothOBS = (TH1D*)f3->Get("T4B");
TH1D *hFourMomentumStoppedOBS = (TH1D*)f3->Get("T4S");
TH1D *hFourMomentumNonStoppedOBS = (TH1D*)f3->Get("T4NS");

TH1D *hQSquaredBothOBS = (TH1D*)f3->Get("Q2B");
TH1D *hQSquaredStoppedOBS = (TH1D*)f3->Get("Q2S");
TH1D *hQSquaredNonStoppedOBS = (TH1D*)f3->Get("Q2NS");


hFourMomentumBothOBS->Sumw2();
hFourMomentumStoppedOBS->Sumw2();
hFourMomentumNonStoppedOBS->Sumw2();
hQSquaredBothOBS->Sumw2();
hQSquaredStoppedOBS->Sumw2();
hQSquaredNonStoppedOBS->Sumw2();




// ###########################################
// # Drawing the Both Information Histograms #
// ###########################################


// ===========================================
//          ### Both Four Momentum ###
// ===========================================
TCanvas *c1 = new TCanvas("c1", "Both Stopped and Non-Stopped Four Momentum |t|");
c1->SetTicks();
c1->SetFillColor(kWhite);

// Area normalizing the plot
hFourMomentumBothBS->Scale(1/hFourMomentumBothBS->Integral());
hFourMomentumBothRS->Scale(1/hFourMomentumBothRS->Integral());
hFourMomentumBothOBS->Scale(1/hFourMomentumBothOBS->Integral());

hFourMomentumBothRS->SetLineColor(kBlue);
hFourMomentumBothRS->SetLineWidth(2);

hFourMomentumBothBS->SetLineColor(kRed);
hFourMomentumBothBS->SetLineWidth(2);

hFourMomentumBothOBS->SetLineColor(kBlack);
hFourMomentumBothOBS->SetLineWidth(2);

hFourMomentumBothBS->GetXaxis()->SetTitle("Four Momentum |t| ((GeV/c^2)^2)");
hFourMomentumBothBS->GetXaxis()->CenterTitle();
hFourMomentumBothBS->GetYaxis()->SetTitle("Normalized Events/Bin Width");
hFourMomentumBothBS->GetYaxis()->CenterTitle();

hFourMomentumBothBS->Draw("histo");
hFourMomentumBothOBS->Draw("histosame");
hFourMomentumBothRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg1 = new TLegend();
leg1 = new TLegend(0.58,0.65,0.88,0.88);
leg1->SetTextSize(0.04);
leg1->SetTextAlign(12);
leg1->SetFillColor(kWhite);
leg1->SetLineColor(kWhite);
leg1->SetShadowColor(kWhite);
leg1->SetHeader("SciBooNE MC");
leg1->AddEntry(hFourMomentumBothRS,"NEUT v5.3.6 Rein-Sehgal");
leg1->AddEntry(hFourMomentumBothBS,"NEUT v5.3.6 Berger-Sehgal");
leg1->AddEntry(hFourMomentumBothOBS,"NEUT v5.0.1 Rein-Sehgal");
leg1->Draw();
// ===========================================


// ===========================================
//           ### Both Q Squared ###
// ===========================================
TCanvas *c2 = new TCanvas("c2", "Both Stopped and Non-Stopped Four Momentum Transfer Q^2");
c2->SetTicks();
c2->SetFillColor(kWhite);

// Area normalizing the plot
hQSquaredBothBS->Scale(1/hQSquaredBothBS->Integral());
hQSquaredBothRS->Scale(1/hQSquaredBothRS->Integral());
hQSquaredBothOBS->Scale(1/hQSquaredBothOBS->Integral());

hQSquaredBothRS->SetLineColor(kBlue);
hQSquaredBothRS->SetLineWidth(2);

hQSquaredBothBS->SetLineColor(kRed);
hQSquaredBothBS->SetLineWidth(2);

hQSquaredBothOBS->SetLineColor(kBlack);
hQSquaredBothOBS->SetLineWidth(2);

hQSquaredBothOBS->GetXaxis()->SetTitle("Four Momentum Transfer Q^2 ((GeV/c^2)^2)");
hQSquaredBothOBS->GetXaxis()->CenterTitle();
hQSquaredBothOBS->GetYaxis()->SetTitle("Normalized Events/Bin Width");
hQSquaredBothOBS->GetYaxis()->CenterTitle();

hQSquaredBothOBS->Draw("histo");
hQSquaredBothBS->Draw("histosame");
hQSquaredBothRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg2 = new TLegend();
leg2 = new TLegend(0.58,0.65,0.88,0.88);
leg2->SetTextSize(0.04);
leg2->SetTextAlign(12);
leg2->SetFillColor(kWhite);
leg2->SetLineColor(kWhite);
leg2->SetShadowColor(kWhite);
leg2->SetHeader("SciBooNE MC");
leg2->AddEntry(hQSquaredBothRS,"NEUT v5.3.6 Rein-Sehgal");
leg2->AddEntry(hQSquaredBothBS,"NEUT v5.3.6 Berger-Sehgal");
leg2->AddEntry(hQSquaredBothOBS,"NEUT v5.0.1 Rein-Sehgal");
leg2->Draw();
// ===========================================

// ###########################################




// ##############################################
// # Drawing the Stopped Information Histograms #
// ##############################################


// ==============================================
//         ### Stopped Four Momentum ###
// ==============================================
TCanvas *c3 = new TCanvas("c3", "Stopped Four Momentum |t|");
c3->SetTicks();
c3->SetFillColor(kWhite);

// Area normalizing the plot
hFourMomentumStoppedBS->Scale(1/hFourMomentumStoppedBS->Integral());
hFourMomentumStoppedRS->Scale(1/hFourMomentumStoppedRS->Integral());
hFourMomentumStoppedOBS->Scale(1/hFourMomentumStoppedOBS->Integral());

hFourMomentumStoppedRS->SetLineColor(kBlue);
hFourMomentumStoppedRS->SetLineWidth(2);

hFourMomentumStoppedBS->SetLineColor(kRed);
hFourMomentumStoppedBS->SetLineWidth(2);

hFourMomentumStoppedOBS->SetLineColor(kBlack);
hFourMomentumStoppedOBS->SetLineWidth(2);

hFourMomentumStoppedBS->GetXaxis()->SetTitle("Four Momentum |t| ((GeV/c^2)^2)");
hFourMomentumStoppedBS->GetXaxis()->CenterTitle();
hFourMomentumStoppedBS->GetYaxis()->SetTitle("Normalized Events/Bin Width");
hFourMomentumStoppedBS->GetYaxis()->CenterTitle();

hFourMomentumStoppedBS->Draw("histo");
hFourMomentumStoppedOBS->Draw("histosame");
hFourMomentumStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg3 = new TLegend();
leg3 = new TLegend(0.58,0.65,0.88,0.88);
leg3->SetTextSize(0.04);
leg3->SetTextAlign(12);
leg3->SetFillColor(kWhite);
leg3->SetLineColor(kWhite);
leg3->SetShadowColor(kWhite);
leg3->SetHeader("SciBooNE MC");
leg3->AddEntry(hFourMomentumStoppedRS,"NEUT v5.3.6 Rein-Sehgal");
leg3->AddEntry(hFourMomentumStoppedBS,"NEUT v5.3.6 Berger-Sehgal");
leg3->AddEntry(hFourMomentumStoppedOBS,"NEUT v5.0.1 Rein-Sehgal");
leg3->Draw();
// ==============================================


// ==============================================
//           ### Stopped Q Squared ###
// ==============================================
TCanvas *c4 = new TCanvas("c4", "Stopped Four Momentum Transfer Q^2");
c4->SetTicks();
c4->SetFillColor(kWhite);

// Area normalizing the plot
hQSquaredStoppedBS->Scale(1/hQSquaredStoppedBS->Integral());
hQSquaredStoppedRS->Scale(1/hQSquaredStoppedRS->Integral());
hQSquaredStoppedOBS->Scale(1/hQSquaredStoppedOBS->Integral());

hQSquaredStoppedRS->SetLineColor(kBlue);
hQSquaredStoppedRS->SetLineWidth(2);

hQSquaredStoppedBS->SetLineColor(kRed);
hQSquaredStoppedBS->SetLineWidth(2);

hQSquaredStoppedOBS->SetLineColor(kBlack);
hQSquaredStoppedOBS->SetLineWidth(2);

hQSquaredStoppedOBS->GetXaxis()->SetTitle("Four Momentum Transfer Q^2 ((GeV/c^2)^2)");
hQSquaredStoppedOBS->GetXaxis()->CenterTitle();
hQSquaredStoppedOBS->GetYaxis()->SetTitle("Normalized Events/Bin Width");
hQSquaredStoppedOBS->GetYaxis()->CenterTitle();

hQSquaredStoppedOBS->Draw("histo");
hQSquaredStoppedBS->Draw("histosame");
hQSquaredStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg4 = new TLegend();
leg4 = new TLegend(0.58,0.65,0.88,0.88);
leg4->SetTextSize(0.04);
leg4->SetTextAlign(12);
leg4->SetFillColor(kWhite);
leg4->SetLineColor(kWhite);
leg4->SetShadowColor(kWhite);
leg4->SetHeader("SciBooNE MC");
leg4->AddEntry(hQSquaredStoppedRS,"NEUT v5.3.6 Rein-Sehgal");
leg4->AddEntry(hQSquaredStoppedBS,"NEUT v5.3.6 Berger-Sehgal");
leg4->AddEntry(hQSquaredStoppedOBS,"NEUT v5.0.1 Rein-Sehgal");
leg4->Draw();
// ==============================================

// ##############################################




// ##################################################
// # Drawing the Non-Stopped Information Histograms #
// ##################################################


// ==================================================
//        ### Non-Stopped Four Momentum ###
// ==================================================
TCanvas *c5 = new TCanvas("c5", "Non-Stopped Four Momentum |t|");
c5->SetTicks();
c5->SetFillColor(kWhite);

// Area normalizing the plot
hFourMomentumNonStoppedBS->Scale(1/hFourMomentumNonStoppedBS->Integral());
hFourMomentumNonStoppedRS->Scale(1/hFourMomentumNonStoppedRS->Integral());
hFourMomentumNonStoppedOBS->Scale(1/hFourMomentumNonStoppedOBS->Integral());

hFourMomentumNonStoppedRS->SetLineColor(kBlue);
hFourMomentumNonStoppedRS->SetLineWidth(2);

hFourMomentumNonStoppedBS->SetLineColor(kRed);
hFourMomentumNonStoppedBS->SetLineWidth(2);

hFourMomentumNonStoppedOBS->SetLineColor(kBlack);
hFourMomentumNonStoppedOBS->SetLineWidth(2);

hFourMomentumNonStoppedBS->GetXaxis()->SetTitle("Four Momentum |t| ((GeV/c^2)^2)");
hFourMomentumNonStoppedBS->GetXaxis()->CenterTitle();
hFourMomentumNonStoppedBS->GetYaxis()->SetTitle("Normalized Events/Bin Width");
hFourMomentumNonStoppedBS->GetYaxis()->CenterTitle();

hFourMomentumNonStoppedBS->Draw("histo");
hFourMomentumNonStoppedOBS->Draw("histosame");
hFourMomentumNonStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg5 = new TLegend();
leg5 = new TLegend(0.58,0.65,0.88,0.88);
leg5->SetTextSize(0.04);
leg5->SetTextAlign(12);
leg5->SetFillColor(kWhite);
leg5->SetLineColor(kWhite);
leg5->SetShadowColor(kWhite);
leg5->SetHeader("SciBooNE MC");
leg5->AddEntry(hFourMomentumNonStoppedRS,"NEUT v5.3.6 Rein-Sehgal");
leg5->AddEntry(hFourMomentumNonStoppedBS,"NEUT v5.3.6 Berger-Sehgal");
leg5->AddEntry(hFourMomentumNonStoppedOBS,"NEUT v5.0.1 Rein-Sehgal");
leg5->Draw();
// ==================================================


// ==================================================
//           ### Non-Stopped Q Squared ###
// ==================================================
TCanvas *c6 = new TCanvas("c6", "Non-Stopped Four Momentum Transfer Q^2");
c6->SetTicks();
c6->SetFillColor(kWhite);

// Area normalizing the plot
hQSquaredNonStoppedBS->Scale(1/hQSquaredNonStoppedBS->Integral());
hQSquaredNonStoppedRS->Scale(1/hQSquaredNonStoppedRS->Integral());
hQSquaredNonStoppedOBS->Scale(1/hQSquaredNonStoppedOBS->Integral());

hQSquaredNonStoppedRS->SetLineColor(kBlue);
hQSquaredNonStoppedRS->SetLineWidth(2);

hQSquaredNonStoppedBS->SetLineColor(kRed);
hQSquaredNonStoppedBS->SetLineWidth(2);

hQSquaredNonStoppedOBS->SetLineColor(kBlack);
hQSquaredNonStoppedOBS->SetLineWidth(2);

hQSquaredNonStoppedBS->GetXaxis()->SetTitle("Four Momentum Transfer Q^2 ((GeV/c^2)^2)");
hQSquaredNonStoppedBS->GetXaxis()->CenterTitle();
hQSquaredNonStoppedBS->GetYaxis()->SetTitle("Normalized Events/Bin Width");
hQSquaredNonStoppedBS->GetYaxis()->CenterTitle();

hQSquaredNonStoppedBS->Draw("histo");
hQSquaredNonStoppedOBS->Draw("histosame");
hQSquaredNonStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg6 = new TLegend();
leg6 = new TLegend(0.58,0.65,0.88,0.88);
leg6->SetTextSize(0.04);
leg6->SetTextAlign(12);
leg6->SetFillColor(kWhite);
leg6->SetLineColor(kWhite);
leg6->SetShadowColor(kWhite);
leg6->SetHeader("SciBooNE MC");
leg6->AddEntry(hQSquaredNonStoppedRS,"NEUT v5.3.6 Rein-Sehgal");
leg6->AddEntry(hQSquaredNonStoppedBS,"NEUT v5.3.6 Berger-Sehgal");
leg6->AddEntry(hQSquaredNonStoppedOBS,"NEUT v5.0.1 Rein-Sehgal");
leg6->Draw();
// ==================================================

// ##################################################
}

