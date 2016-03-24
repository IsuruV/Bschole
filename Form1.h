#include <sstream>
#include <iostream>
#include <string> 
#include <iomanip>
#include <math.h>
using namespace std;

#pragma once

namespace BlackSch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

	// Functions   Reference: espenhaug.com/black_scholes.html 
		
       #ifndef Pi 
       #define Pi 3.141592653589793238462643 
       #endif 
// Cumulative Normal Distribution Function
		double CND( double X )
      {

         double L, K, w ;

         double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
         double const a4 = -1.821255978, a5 = 1.330274429;

          L = fabs(X);
          K = 1.0 / (1.0 + 0.2316419 * L);
         w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) 
			 + a4 * pow(K,4) + a5 * pow(K,5));

            if (X < 0 ){
          w= 1.0 - w;
            }
          return w;

}  // End_CND
// Cumulative Normal Distribution Funciton_End

// Black Scholes 
		double BlackScholes(char CallPutFlag, double S, double X, double T, double r, double v)
          {
            double d1, d2;


            d1=(log(S/X)+(r+v*v/2)*T)/(v*sqrt(T));
            d2=d1-v*sqrt(T);

             if(CallPutFlag == 'c')
             return S *CND(d1)-X * exp(-r*T)*CND(d2);
             else if(CallPutFlag == 'p')
             return X * exp(-r * T) * CND(-d2) - S * CND(-d1);
            }
// Black Scholes_End


		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here 
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tbStockPrice;
	private: System::Windows::Forms::Label^  LStockPrice;

	protected: 

	private: System::Windows::Forms::TextBox^  tbVolatility;
	private: System::Windows::Forms::Label^  LVolatility;

	private: System::Windows::Forms::TextBox^  tbStrikePrice;
	private: System::Windows::Forms::Label^  LStrikePrice;



	private: System::Windows::Forms::TextBox^  tbRiskFreeRate;
	private: System::Windows::Forms::Label^  LRiskFreeRate;
	private: System::Windows::Forms::Label^  LCurrentDate;
	private: System::Windows::Forms::Label^  LExpirationDate;
	private: System::Windows::Forms::Label^  LCallPrice;


	private: System::Windows::Forms::TextBox^  tbCallPrice;
	private: System::Windows::Forms::Label^  LPutPrice;


	private: System::Windows::Forms::TextBox^  tbPutPrice;
	private: System::Windows::Forms::Button^  Calculate;
	private: System::Windows::Forms::DateTimePicker^  CurrentDate;
	private: System::Windows::Forms::DateTimePicker^  ExpirationDate;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbStockPrice = (gcnew System::Windows::Forms::TextBox());
			this->LStockPrice = (gcnew System::Windows::Forms::Label());
			this->tbVolatility = (gcnew System::Windows::Forms::TextBox());
			this->LVolatility = (gcnew System::Windows::Forms::Label());
			this->tbStrikePrice = (gcnew System::Windows::Forms::TextBox());
			this->LStrikePrice = (gcnew System::Windows::Forms::Label());
			this->tbRiskFreeRate = (gcnew System::Windows::Forms::TextBox());
			this->LRiskFreeRate = (gcnew System::Windows::Forms::Label());
			this->LCurrentDate = (gcnew System::Windows::Forms::Label());
			this->LExpirationDate = (gcnew System::Windows::Forms::Label());
			this->LCallPrice = (gcnew System::Windows::Forms::Label());
			this->tbCallPrice = (gcnew System::Windows::Forms::TextBox());
			this->LPutPrice = (gcnew System::Windows::Forms::Label());
			this->tbPutPrice = (gcnew System::Windows::Forms::TextBox());
			this->Calculate = (gcnew System::Windows::Forms::Button());
			this->CurrentDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->ExpirationDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// tbStockPrice
			// 
			this->tbStockPrice->Location = System::Drawing::Point(257, 44);
			this->tbStockPrice->Multiline = true;
			this->tbStockPrice->Name = L"tbStockPrice";
			this->tbStockPrice->Size = System::Drawing::Size(242, 30);
			this->tbStockPrice->TabIndex = 0;
		
			// 
			// LStockPrice
			// 
			this->LStockPrice->AutoSize = true;
			this->LStockPrice->Location = System::Drawing::Point(95, 44);
			this->LStockPrice->Name = L"LStockPrice";
			this->LStockPrice->Size = System::Drawing::Size(85, 20);
			this->LStockPrice->TabIndex = 1;
			this->LStockPrice->Text = L"StockPrice";
			this->LStockPrice->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// tbVolatility
			// 
			this->tbVolatility->Location = System::Drawing::Point(258, 99);
			this->tbVolatility->Name = L"tbVolatility";
			this->tbVolatility->Size = System::Drawing::Size(242, 26);
			this->tbVolatility->TabIndex = 2;
			// 
			// LVolatility
			// 
			this->LVolatility->AutoSize = true;
			this->LVolatility->Location = System::Drawing::Point(95, 99);
			this->LVolatility->Name = L"LVolatility";
			this->LVolatility->Size = System::Drawing::Size(67, 20);
			this->LVolatility->TabIndex = 3;
			this->LVolatility->Text = L"Volatility";
			this->LVolatility->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// tbStrikePrice
			// 
			this->tbStrikePrice->Location = System::Drawing::Point(259, 155);
			this->tbStrikePrice->Name = L"tbStrikePrice";
			this->tbStrikePrice->Size = System::Drawing::Size(241, 26);
			this->tbStrikePrice->TabIndex = 4;
			// 
			// LStrikePrice
			// 
			this->LStrikePrice->AutoSize = true;
			this->LStrikePrice->Location = System::Drawing::Point(95, 155);
			this->LStrikePrice->Name = L"LStrikePrice";
			this->LStrikePrice->Size = System::Drawing::Size(89, 20);
			this->LStrikePrice->TabIndex = 5;
			this->LStrikePrice->Text = L"Strike Price";
			this->LStrikePrice->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// tbRiskFreeRate
			// 
			this->tbRiskFreeRate->Location = System::Drawing::Point(259, 210);
			this->tbRiskFreeRate->Name = L"tbRiskFreeRate";
			this->tbRiskFreeRate->Size = System::Drawing::Size(242, 26);
			this->tbRiskFreeRate->TabIndex = 6;
			// 
			// LRiskFreeRate
			// 
			this->LRiskFreeRate->AutoSize = true;
			this->LRiskFreeRate->Location = System::Drawing::Point(95, 210);
			this->LRiskFreeRate->Name = L"LRiskFreeRate";
			this->LRiskFreeRate->Size = System::Drawing::Size(116, 20);
			this->LRiskFreeRate->TabIndex = 7;
			this->LRiskFreeRate->Text = L"Risk Free Rate";
			this->LRiskFreeRate->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// LCurrentDate
			// 
			this->LCurrentDate->AutoSize = true;
			this->LCurrentDate->Location = System::Drawing::Point(95, 294);
			this->LCurrentDate->Name = L"LCurrentDate";
			this->LCurrentDate->Size = System::Drawing::Size(101, 20);
			this->LCurrentDate->TabIndex = 9;
			this->LCurrentDate->Text = L"Current Date";
			// 
			// LExpirationDate
			// 
			this->LExpirationDate->AutoSize = true;
			this->LExpirationDate->Location = System::Drawing::Point(95, 334);
			this->LExpirationDate->Name = L"LExpirationDate";
			this->LExpirationDate->Size = System::Drawing::Size(118, 20);
			this->LExpirationDate->TabIndex = 11;
			this->LExpirationDate->Text = L"Expiration Date";
			// 
			// LCallPrice
			// 
			this->LCallPrice->AutoSize = true;
			this->LCallPrice->Location = System::Drawing::Point(95, 424);
			this->LCallPrice->Name = L"LCallPrice";
			this->LCallPrice->Size = System::Drawing::Size(74, 20);
			this->LCallPrice->TabIndex = 13;
			this->LCallPrice->Text = L"Call Price";
			// 
			// tbCallPrice
			// 
			this->tbCallPrice->BackColor = System::Drawing::Color::LightGreen;
			this->tbCallPrice->Location = System::Drawing::Point(258, 424);
			this->tbCallPrice->Name = L"tbCallPrice";
			this->tbCallPrice->ReadOnly = true;
			this->tbCallPrice->Size = System::Drawing::Size(242, 26);
			this->tbCallPrice->TabIndex = 14;
			// 
			// LPutPrice
			// 
			this->LPutPrice->AutoSize = true;
			this->LPutPrice->Location = System::Drawing::Point(95, 470);
			this->LPutPrice->Name = L"LPutPrice";
			this->LPutPrice->Size = System::Drawing::Size(72, 20);
			this->LPutPrice->TabIndex = 15;
			this->LPutPrice->Text = L"Put Price";
			// 
			// tbPutPrice
			// 
			this->tbPutPrice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->tbPutPrice->Location = System::Drawing::Point(258, 470);
			this->tbPutPrice->Name = L"tbPutPrice";
			this->tbPutPrice->ReadOnly = true;
			this->tbPutPrice->Size = System::Drawing::Size(241, 26);
			this->tbPutPrice->TabIndex = 16;
			// 
			// Calculate
			// 
			this->Calculate->BackColor = System::Drawing::SystemColors::Info;
			this->Calculate->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Calculate->Location = System::Drawing::Point(603, 447);
			this->Calculate->Name = L"Calculate";
			this->Calculate->Size = System::Drawing::Size(133, 66);
			this->Calculate->TabIndex = 17;
			this->Calculate->Text = L"Calculate";
			this->Calculate->UseVisualStyleBackColor = false;
			this->Calculate->Click += gcnew System::EventHandler(this, &Form1::Calculate_Click);
			// 
			// CurrentDate
			// 
			this->CurrentDate->Location = System::Drawing::Point(257, 294);
			this->CurrentDate->Name = L"CurrentDate";
			this->CurrentDate->Size = System::Drawing::Size(308, 26);
			this->CurrentDate->TabIndex = 19;
			// 
			// ExpirationDate
			// 
			this->ExpirationDate->Location = System::Drawing::Point(257, 334);
			this->ExpirationDate->Name = L"ExpirationDate";
			this->ExpirationDate->Size = System::Drawing::Size(308, 26);
			this->ExpirationDate->TabIndex = 20;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(872, 547);
			this->Controls->Add(this->ExpirationDate);
			this->Controls->Add(this->CurrentDate);
			this->Controls->Add(this->Calculate);
			this->Controls->Add(this->tbPutPrice);
			this->Controls->Add(this->LPutPrice);
			this->Controls->Add(this->tbCallPrice);
			this->Controls->Add(this->LCallPrice);
			this->Controls->Add(this->LExpirationDate);
			this->Controls->Add(this->LCurrentDate);
			this->Controls->Add(this->LRiskFreeRate);
			this->Controls->Add(this->tbRiskFreeRate);
			this->Controls->Add(this->LStrikePrice);
			this->Controls->Add(this->tbStrikePrice);
			this->Controls->Add(this->LVolatility);
			this->Controls->Add(this->tbVolatility);
			this->Controls->Add(this->LStockPrice);
			this->Controls->Add(this->tbStockPrice);
			this->Name = L"Form1";
			this->Text = L"Black Scholes Options Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	        private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	        private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
            private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		     }

// ButtonCalculate
private: System::Void Calculate_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 
			 double stockPrice; //Get the StockPrice//
			 stockPrice = Convert::ToDouble(tbStockPrice->Text);

			 double volatility;  //Get the Volatility// 
			 volatility = Convert::ToDouble(tbVolatility->Text);

			 double strikePrice; // Get the strick Price//
			 strikePrice = Convert::ToDouble(tbStrikePrice->Text);

			 double riskFreeRate; // Get the risk free rate//
			 riskFreeRate = Convert::ToDouble(tbRiskFreeRate->Text);

			 System::TimeSpan daysdiff;  // Get the Time Difference as a fraction of a year// 
			 double yearsdiff;
			 daysdiff = this->ExpirationDate->Value - this->CurrentDate->Value;
			 yearsdiff = ((double) daysdiff.Days/365.0);

			 // Calculates the Call Price
			 double BscholeCall= BlackScholes('c',stockPrice,strikePrice,riskFreeRate,yearsdiff,volatility);
			 // Calculates the Put Price
			 double BscholePut= BlackScholes('p',stockPrice,strikePrice,riskFreeRate,yearsdiff,volatility);

			 tbCallPrice ->Text=Convert::ToString(BscholeCall);
			 tbPutPrice ->Text=Convert::ToString(BscholePut);

			
			
		 } //end_ButtonCalculate

};
}

//	this->tbStockPrice->TextChanged += gcnew System::EventHandler(this, &Form1::tbStockPrice_TextChanged);