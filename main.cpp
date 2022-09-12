#include <wx/wx.h>
#include <wx/splitter.h>

#include <wx/grid.h>


namespace Examples
{
  // enum IDs{
  //   Button_ID = 2,
  //   Slider_ID = 3,
  //   TEXT_ID = 4
  // };
  // EVT_BUTTON(Button_ID, myFrame::O)

//   class StretchGrid : public wxGrid
// {
// public:
//     StretchGrid (wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
// 	       long style = wxWANTS_CHARS, const wxString& name = wxGridNameStr);
//     ~StretchGrid ();
    
// protected:
//     void OnGridWindowSize (wxSizeEvent& event);
//     void OnColHeaderSize (wxGridSizeEvent& event);
//     void AutoSizeLastCol ();
// };
// StretchGrid::StretchGrid (wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) :
// 			wxGrid (parent, id, pos, size, style, name)
// {
//     GetGridWindow()->Bind (wxEVT_SIZE, &StretchGrid::OnGridWindowSize, this);
//     Bind (wxEVT_GRID_COL_SIZE, &StretchGrid::OnColHeaderSize, this);
// }

// StretchGrid::~StretchGrid()
// {
//     GetGridWindow()->Unbind (wxEVT_SIZE, &StretchGrid::OnGridWindowSize, this);
//     Unbind (wxEVT_GRID_COL_SIZE, &StretchGrid::OnColHeaderSize, this);
// }

// void StretchGrid::OnGridWindowSize (wxSizeEvent& event)
// {
//     if (GetNumberCols() > 0)
//         AutoSizeLastCol ();
// }

// void StretchGrid::OnColHeaderSize (wxGridSizeEvent& event)
// {
//     if (GetNumberCols() > 0)
//         AutoSizeLastCol ();
// }

// void StretchGrid::AutoSizeLastCol ()
// {
//     int colWidths = 0;
    
//     for (int i = 0; i < GetNumberCols() - 1; i++)
//         colWidths += GetColWidth (i);
    
//     int finalColWidth = GetGridWindow()->GetSize().x - colWidths;
         
    
//     if (finalColWidth > 80)
//         SetColSize (GetNumberCols() - 1, finalColWidth);
//     else
//         SetColSize (GetNumberCols() - 1, 80);
// }

class MovableButton : public wxButton
{
	bool dragging;
	int x,y;
	wxPanel* parent;
public:
	
	MovableButton(wxPanel* parent,wxSize k) : wxButton(parent, wxID_ANY, wxT("Drag me around"))
	{
		MovableButton::parent = parent;
    MovableButton::SetSize(k);
		dragging = false;
	}
		
	void onMouseDown(wxMouseEvent& evt)
	{
		CaptureMouse();
		x = evt.GetX();
		y = evt.GetY();
		dragging=true;
	}
	void onMouseUp(wxMouseEvent& evt)
	{
		ReleaseMouse();
		dragging=false;
	}
	void onMove(wxMouseEvent& evt)
	{
		if(dragging)
		{
			wxPoint mouseOnScreen = wxGetMousePosition();
			int newx = mouseOnScreen.x - x;
			int newy = mouseOnScreen.y - y;
			this->Move( parent->ScreenToClient( wxPoint(newx, newy) ) );
		}
	}
	
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MovableButton,wxButton)
EVT_LEFT_DOWN(MovableButton::onMouseDown)
EVT_LEFT_UP(MovableButton::onMouseUp)
EVT_MOTION(MovableButton::onMove)
END_EVENT_TABLE()


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


    // sizer = wx.BoxSizer(wx.VERTICAL)
    // image_panel = ImagePanel(main_panel)
    // sizer.Add(image_panel, 1, wx.EXPAND|wx.ALL, 5)

    // # Add your control panel here

    // main_panel.SetSizer(sizer)
    // self.Centre()
    // self.Show()

    // wxButton *button = new wxButton(left,Button_ID,"clickme",wxPoint(300,275),wxSize(50,50));
    // wxSlider *slider = new wxSlider(left,Slider_ID,0,0,100,wxPoint(300,275),wxSize(200,-1));
    // wxTextCtrl *text = new wxTextCtrl(left,TEXT_ID,"",wxPoint(300,375),wxSize(200,-1));
    // wxButton *button = new wxButton(left,wxID_ANY,"clickme",wxPoint(300,275),wxSize(50,-1));
    // button->Bind(wxEVT_BUTTON,&myFrame::OnbuttonClicked,this);
    // wxSlider *slider = new wxSlider(left,wxID_ANY,0,0,100,wxPoint(300,275),wxSize(200,-1));
    // slider->Bind(wxEVT_SLIDER,&myFrame::SliderChange,this);
    // wxTextCtrl *text = new wxTextCtrl(left,wxID_ANY,"",wxPoint(300,375),wxSize(200,-1));
    // text->Bind(wxEVT_TEXT,&myFrame::TextChange,this);
    wxBoxSizer *split = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *rightsizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *leftsizer = new wxBoxSizer(wxVERTICAL);
    // create text ctrl with minimal size 100x60 that is horizontally and
    // vertically stretchable with a border width of 10
    leftsizer->Add(
        new wxStaticText(this, wxID_ANY, "Zasifrovat"),
        wxSizerFlags(0.5).Border(wxALL, 10));
        wxTextCtrl *input = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(100, 60), wxTE_MULTILINE);
        input->Bind(wxEVT_TEXT,&myFrame::TextChange,this);
    leftsizer->Add(
        input,
        wxSizerFlags(1).Top().Expand().Border(wxALL, 10));
    leftsizer->Add(
        new wxStaticText(this, wxID_ANY, "Zasifrovane"),
        wxSizerFlags(0.5).Border(wxALL, 10));
    leftsizer->Add(
        new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(100, 60), wxTE_MULTILINE),
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
    leftsizer->Add(
        button_sizer,
        wxSizerFlags(0).Center());


    wxGrid *grid = new wxGrid(this,wxID_ANY);
    grid->CreateGrid(21,12);

    for(int i = 0; i < 21*12;i++){
      grid->SetCellValue(1,0, wxString::Format("%.2d", i));
    }

    grid->InvalidateBestSize();
    SetClientSize(grid->GetBestSize());

          rightsizer->Add(
        grid,
        wxSizerFlags(0.5).Border(wxALL, 10));


    // grid->Move(20,50,wxSIZE_USE_EXISTING);
    split->Add(leftsizer,wxSizerFlags(1).Expand());

    //animation
    //wxBoxSizer *bottom = new wxBoxSizer(wxHORIZONTAL);
    wxPanel *dum = new wxPanel(this);
    MovableButton *x = new MovableButton(dum,DoGetBestClientSize());
    x->Move(100,10);
    //dum->SetSizer(bottom);
    rightsizer->Add(dum,wxSizerFlags(1));
    //

    split->Add(rightsizer,wxSizerFlags(2));

   
    
    SetSizerAndFit(split); // use the sizer for layout and set size and hints
    // wxButton *button = new wxButton(left,wxID_ANY,"clickme",wxPoint(300,275),wxSize(50,-1));
    // button->Bind(wxEVT_BUTTON,&myFrame::OnbuttonClicked,this);
    // wxSlider *slider = new wxSlider(left,wxID_ANY,0,0,100,wxPoint(300,275),wxSize(200,-1));
    // slider->Bind(wxEVT_SLIDER,&myFrame::SliderChange,this);
    // wxTextCtrl *text = new wxTextCtrl(left,wxID_ANY,"",wxPoint(300,375),wxSize(200,-1));
    // text->Bind(wxEVT_TEXT,&myFrame::TextChange,this);
    // SetSizerAndFit(leftsizer);

    // button->Unbind(wxEVT_BUTTON,&myFrame::OnbuttonClicked,this);

    // left->SetBackgroundColour(wxColor(200,100,100));
    // right->SetBackgroundColour(wxColor(200,50,0));

    // splitter->SplitVertically(left,right);
    CreateStatusBar();
  }

}

wxIMPLEMENT_APP(Examples::Application);
