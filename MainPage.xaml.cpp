//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace MMSS_Timer;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

Boolean is_paused, is_restart;
time_t start_time, curr_time, duration;

MainPage::MainPage()
{
	is_paused = false; //Starts false, timer is paused
	is_restart = true; //Starts true, first run is a new start
	InitializeComponent();
}

void MMSS_Timer::MainPage::Start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (is_restart) {	//If this is the first time run or if the flag to restart the timer is set, set starting time to current time
		start_time = time(0);
		is_restart = !is_restart; //Set flag to indicate future starts from paused will be the last marked start time.
	}
	is_paused = !is_paused; //Timer is started or paused depending on previous state
	do {
		curr_time = time(0);
		duration = curr_time - start_time;
		
		//MMSS_Timer::MainPage::timerOutput->Text = duration;
	} while (is_paused);
	
}


void MMSS_Timer::MainPage::Reset_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Reset timer to 0
	is_restart = false; //This flag indicates that the time will restart on the next time run
}

