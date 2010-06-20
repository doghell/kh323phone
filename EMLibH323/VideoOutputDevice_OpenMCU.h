#pragma once

class CVideoOutputDevice_OpenMCU
	: public PVideoOutputDevice
{
	PCLASSINFO(CVideoOutputDevice_OpenMCU, PVideoOutputDevice);
public:
	CVideoOutputDevice_OpenMCU(H323Connection & _mcuConnection);
	virtual ~CVideoOutputDevice_OpenMCU(void);

    /**Get a list of all of the drivers available.
      */
    static PStringList GetOutputDeviceNames();

    virtual PStringList GetDeviceNames() const
      { return GetOutputDeviceNames(); }

    /**Open the device given the device name.
      */
    virtual BOOL Open(
      const PString & deviceName,   /// Device name to open
      BOOL startImmediate = TRUE    /// Immediately start device
    );

    /**Start the video device I/O.
      */
    BOOL Start();

    /**Stop the video device I/O capture.
      */
    BOOL Stop();

    /**Close the device.
      */
    virtual BOOL Close();

    /**Determine if the device is currently open.
      */
    virtual BOOL IsOpen();

    /**Get the maximum frame size in bytes.

       Note a particular device may be able to provide variable length
       frames (eg motion JPEG) so will be the maximum size of all frames.
      */
    virtual PINDEX GetMaxFrameBytes();

    /**Set a section of the output frame buffer.
      */
    virtual BOOL SetFrameData(
      unsigned x,
      unsigned y,
      unsigned width,
      unsigned height,
      const BYTE * data,
      BOOL endFrame = TRUE
    );

    /**Indicate frame may be displayed.
      */
    virtual BOOL EndFrame();

	void SetIHPVideoOutput(IHPVideoOutput*pIHPVideoOutput);

protected:  
    H323Connection & mcuConnection;
	IHPVideoOutput*	m_pIHPVideoOutput;
};
