/**
 * @file ViewTimeline.h
 * @author Charles B. Owen
 *
 * View class for the timeline area of the screen.
 */

#ifndef CANADIANEXPERIENCE_VIEWTIMELINE_H
#define CANADIANEXPERIENCE_VIEWTIMELINE_H

#include "PictureObserver.h"

/**
 * View class for the timeline area of the screen.
 */
class ViewTimeline final : public wxScrolledCanvas, public PictureObserver{
private:
	/// Bitmap image for the pointer
	std::unique_ptr<wxImage> mPointerImage;

	/// Graphics bitmap to display
	wxGraphicsBitmap mPointerBitmap;

	/// Flag to indicate we are moving the pointer
	bool mMovingPointer = false;

	void OnLeftDown(wxMouseEvent &event);
	void OnLeftUp(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);

	void OnSetKeyframe(wxCommandEvent &event);
	void OnDeleteKeyframe(wxCommandEvent &event);


	void OnEditTimelineProperties(wxCommandEvent& event);

public:

    static const int Height = 90;      ///< Height to make this window

    ViewTimeline(wxFrame* parent,std::wstring imagesDir);

	void UpdateObserver() override;
};


#endif //CANADIANEXPERIENCE_VIEWTIMELINE_H
