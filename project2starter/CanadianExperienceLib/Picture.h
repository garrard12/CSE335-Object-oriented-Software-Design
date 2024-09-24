/**
 * @file Picture.h
 *
 * @author Charles B. Owen
 *
 *  Class that represents our animation picture
 */

#pragma once

#include "Timeline.h"
#include "MachineDrawable.h"

class PictureObserver;
class Actor;

/**
 *  Class that represents our animation picture
 */
class Picture
{
private:
    /// The picture size
    wxSize mSize = wxSize(1500, 800);

    /// The observers of this picture
    std::vector<PictureObserver *> mObservers;

    /// The actors associated with this picture
    std::vector<std::shared_ptr<Actor>> mActors;

    /// The animation timeline
    Timeline mTimeline;

	//MachineDrawable mMachineDrawable;

	/// Load in Machine one
	wxString mLoadMachineOne;
	/// Load in Machine two
	wxString mLoadMachineTwo;

	/// Machine one to be draw
	std::shared_ptr<MachineDrawable> mMachineOne;
	/// Machine two to be draw
	std::shared_ptr<MachineDrawable> mMachineTwo;

public:
    Picture();

    /// Copy Constructor (Disabled)
    Picture(const Picture &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Picture &) = delete;

    /**
     * Destructor
    */
    virtual ~Picture() = default;

    /**
     * Get the picture size
     * @return Picture size in pixels
     */
    wxSize GetSize() {return mSize;}

    /**
     * Set the picture size
     * @param size Picture size in pixels
     */
    void SetSize(wxSize size) {mSize = size;}

    /**
     * Get a pointer to the Timeline object
     * @return Pointer to the Timeline object
     */
    Timeline *GetTimeline() {return &mTimeline;}

    void AddObserver(PictureObserver *observer);
    void RemoveObserver(PictureObserver *observer);
    void UpdateObservers();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void AddActor(std::shared_ptr<Actor> actor);

    /** Iterator that iterates over the actors in a picture */
    class ActorIter
    {
    public:
        /**
         * Constructor
         * @param picture Picture we are iterating
         * @param pos Starting position \
         */
        ActorIter(Picture *picture, int pos) : mPicture(picture), mPos(pos) {}

        /**
         * Test for end of the iterator
         * @param other Other object to test against
         * @return True if we this position equals not equal to the other position
         */
        bool operator!=(const ActorIter &other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
        * @return Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        Picture *mPicture;  ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    ActorIter begin() { return ActorIter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    ActorIter end() { return ActorIter(this, mActors.size()); }

    void SetAnimationTime(double time);

    double GetAnimationTime();

    void Load(const wxString& filename);

    void Save(const wxString& filename);

	void MachineDiaglog(wxWindow* parent, int number);

	/**
	 * Set the machine for the first machine
	 * @param machine The machine to set
	 */
	void SetMachineone(std::shared_ptr<MachineDrawable> machine){mMachineOne = machine;}
	/**
	 * Set the machine for the second machine
	 * @param machine The machine to set
	 */
	void SetMachinetwo(std::shared_ptr<MachineDrawable> machine){mMachineTwo= machine;}
	/**
	 * Get the machine One
	 * @return Machine one
	 */
	double GetStartTimeMachineOne() {return mMachineOne->GetStartTime();}

	//double GetEndTimeMachineOne(){return mMachineOne->GetEndTime();}
	/**
	 * Set the start time for machine one
	 * @param start The wanted start time
	 */
	void SetStartTimeMachineOne(double start){mMachineOne->SetStartTime(start);}
	/**
	 * Set the start time for machine two
	 * @param start The wanted start time
	 */
	void SetStartTimeMachineTwo(double start){mMachineTwo->SetStartTime(start);}
	//void SetEndTime(double end){mMachineOne->SetEndTime(end);}
};

