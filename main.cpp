#include <wx/wx.h>
#include <wx/splitter.h>

namespace Examples
{
  // enum IDs{
  //   Button_ID = 2,
  //   Slider_ID = 3,
  //   TEXT_ID = 4
  // };
  // EVT_BUTTON(Button_ID, myFrame::O)

  class Application : public wxApp
  {
  public:
    virtual bool OnInit();
  };

  class myFrame : public wxFrame
  {
  public:
    myFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    wxString greeting = "Hi";

  private:
    void OnbuttonClicked(wxCommandEvent &event);
    void SliderChange(wxCommandEvent &event);
    void TextChange(wxCommandEvent &event);
    // wxDECLARE_EVENT_TABLE();
  };

  // wxBEGIN_EVENT_TABLE(myFrame,wxFrame)
  //   EVT_BUTTON(Button_ID, myFrame::OnbuttonClicked)
  //   EVT_TEXT(TEXT_ID,myFrame::TextChange)
  //   EVT_SLIDER(Slider_ID,myFrame::SliderChange)
  // wxEND_EVENT_TABLE()

  void myFrame::OnbuttonClicked(wxCommandEvent &event)
  {
    wxLogStatus(wxString::Format("Sussywussy %s", greeting));
  }
  void myFrame::TextChange(wxCommandEvent &event)
  {
    greeting = event.GetString();
    wxLogStatus(wxString::Format("Entered %s", event.GetString()));
  }
  void myFrame::SliderChange(wxCommandEvent &event)
  {
    wxLogStatus(wxString::Format("Slider value %d", event.GetInt()));
  }

  bool Application::OnInit()
  {
    myFrame *frame = new myFrame("Hi mark", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
  }

  myFrame::myFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
  {
    // wxSplitterWindow *splitter = new wxSplitterWindow(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxSP_BORDER | wxSP_LIVE_UPDATE);
    // wxPanel *left = new wxPanel(splitter);
    // wxPanel *right = new wxPanel(splitter);

    // wxButton *button = new wxButton(left,Button_ID,"clickme",wxPoint(300,275),wxSize(50,50));
    // wxSlider *slider = new wxSlider(left,Slider_ID,0,0,100,wxPoint(300,275),wxSize(200,-1));
    // wxTextCtrl *text = new wxTextCtrl(left,TEXT_ID,"",wxPoint(300,375),wxSize(200,-1));
    // wxButton *button = new wxButton(left,wxID_ANY,"clickme",wxPoint(300,275),wxSize(50,-1));
    // button->Bind(wxEVT_BUTTON,&myFrame::OnbuttonClicked,this);
    // wxSlider *slider = new wxSlider(left,wxID_ANY,0,0,100,wxPoint(300,275),wxSize(200,-1));
    // slider->Bind(wxEVT_SLIDER,&myFrame::SliderChange,this);
    // wxTextCtrl *text = new wxTextCtrl(left,wxID_ANY,"",wxPoint(300,375),wxSize(200,-1));
    // text->Bind(wxEVT_TEXT,&myFrame::TextChange,this);

    wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
    // create text ctrl with minimal size 100x60 that is horizontally and
    // vertically stretchable with a border width of 10
    topsizer->Add(
        new wxStaticText(this, wxID_ANY, "Zasifrovat"),
        wxSizerFlags(0.5).Border(wxALL, 10));

        wxTextCtrl *input = new wxTextCtrl(this, -1, "My text.", wxDefaultPosition, wxSize(100, 60), wxTE_MULTILINE);
        input->Bind(wxEVT_TEXT,&myFrame::TextChange,this);
    topsizer->Add(
        input,
        wxSizerFlags(1).Top().Expand().Border(wxALL, 10));
    topsizer->Add(
        new wxStaticText(this, wxID_ANY, "Zasifrovane"),
        wxSizerFlags(0.5).Border(wxALL, 10));
    topsizer->Add(
        new wxTextCtrl(this, -1, "My text.", wxDefaultPosition, wxSize(100, 60), wxTE_MULTILINE),
        wxSizerFlags(1).Top().Expand().Border(wxALL, 10));
    wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    // create two buttons that are horizontally unstretchable,
    //  with an all-around border with a width of 10 and implicit top alignment
    wxButton *okButton =  new wxButton(this, wxID_OK, "OK");
    okButton->Bind(wxEVT_BUTTON,&myFrame::OnbuttonClicked,this);
    button_sizer->Add(
        okButton,
        wxSizerFlags(0).Top().Border(wxALL, 10));
    button_sizer->Add(
        new wxButton(this, wxID_CANCEL, "Cancel"),
        wxSizerFlags(0).Top().Border(wxALL, 10));
    // create a sizer with no border and centered horizontally
    topsizer->Add(
        button_sizer,
        wxSizerFlags(0).Center());
    SetSizerAndFit(topsizer); // use the sizer for layout and set size and hints
    // wxButton *button = new wxButton(left,wxID_ANY,"clickme",wxPoint(300,275),wxSize(50,-1));
    // button->Bind(wxEVT_BUTTON,&myFrame::OnbuttonClicked,this);
    // wxSlider *slider = new wxSlider(left,wxID_ANY,0,0,100,wxPoint(300,275),wxSize(200,-1));
    // slider->Bind(wxEVT_SLIDER,&myFrame::SliderChange,this);
    // wxTextCtrl *text = new wxTextCtrl(left,wxID_ANY,"",wxPoint(300,375),wxSize(200,-1));
    // text->Bind(wxEVT_TEXT,&myFrame::TextChange,this);
    // SetSizerAndFit(topsizer);

    // button->Unbind(wxEVT_BUTTON,&myFrame::OnbuttonClicked,this);

    // left->SetBackgroundColour(wxColor(200,100,100));
    // right->SetBackgroundColour(wxColor(200,50,0));

    // splitter->SplitVertically(left,right);
    CreateStatusBar();
  }

}

wxIMPLEMENT_APP(Examples::Application);
