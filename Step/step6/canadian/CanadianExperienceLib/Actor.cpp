/**
 * @file Actor.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Actor.h"
#include "Drawable.h"
#include "Picture.h"

/**
 * Constructor
 * @param name The actor name
 */
Actor::Actor(const std::wstring &name) : mName(name)
{

}
/**
* Add a drawable to this actor
* @param drawable The drawable to add
*/
void Actor::AddDrawable(std::shared_ptr<Drawable> drawable)
{
	//This set the association in both directions
	//Most will do it in both directions
	mDrawablesInOrder.push_back(drawable);
	drawable->SetActor(this);
}
/**
* Test to see if a mouse click is on this actor.
* @param pos Mouse position on drawing
* @return A drawable object we clicked on or nullptr if we missed.
*/
std::shared_ptr<Drawable> Actor::HitTest(wxPoint pos)
{
	// If not enabled or not clickable, we indicate no hit.
	if (!mClickable || !mEnabled)
		return nullptr;

	// Since this list is in drawing order, we really want to know the last thing drawn
	// under the mouse, since it will be on top. So, we reverse iterate over the list.
	for (auto d = mDrawablesInOrder.rbegin(); d != mDrawablesInOrder.rend(); d++)
	{
		auto drawable = *d;
		if (drawable->HitTest(pos))
			return drawable;
	}

	return nullptr;
}
/**
 * Draw this actor
 * @param gc The Graphics object we are drawing on
 */
void Actor::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	// Don't draw if not enabled
	if(!mEnabled)
		return;

	// This takes care of determining the absolute placement
	// of all of the child drawables. We have to determine this
	// in tree order, which may not be the order we draw.
	if(mRoot != nullptr)
		mRoot->Place(mPosition, 0);

	for(auto drawable : mDrawablesInOrder)
	{
		drawable->Draw(gc);
	}
}
/**
 * Set the root drawable for the actor
 * @param root Pointer to root drawable
 */
void Actor::SetRoot(std::shared_ptr<Drawable> root)
{
	mRoot = root;
}
/**
 * Set the picture for to Draw
 * @param picture The picture to draw
 */
void Actor::SetPicture(Picture *picture)
{
	mPicture = picture;
}
