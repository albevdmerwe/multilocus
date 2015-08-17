/**************************************************************************ConsoleApp - simple text console based application & UI functionsCredits:- By Paul-Michael Agapow, 2003, Dept. Biology, University College  London, London WC1E 6BT, UK.- <mail://p.agapow@ucl.ac.uk> <mail://a.burt@ic.ac.uk>  <http://www.bio.ic.ac.uk/evolve/>About:- Derive from this to make bog-standard, C++ apps.**************************************************************************/#ifndef CONSOLEAPP_H#define CONSOLEAPP_H// *** INCLUDES#include "Sbl.h"#include "Error.h"#include <string>#include <vector>SBL_NAMESPACE_START// *** CONSTANTS & DEFINESstruct answerbounds_t{ };static answerbounds_t kNoBound;// *** CLASS DECLARATION *************************************************/class ConsoleApp{public:	// Lifecycle	ConsoleApp	();	~ConsoleApp	();			// Services			virtual void	Startup				();		// can override	virtual void	Run					() = 0;	// _must_ override in derived class	virtual void	Quit					();		// can override	// Aboutbox display	virtual void	ShowAboutBox		();		// can override	void				PrintAboutString	(std::string& iContentString);	void				PrintAboutBorder	();	// UI functions	void			PrintQuestion		(std::string *iPromptString);	void			PrintQuestion		(std::string &iPromptString);	void			PrintQuestion		(const char* iPromptCstr);	std::string	getAnswer ();	void			Report				(const char* iPrompt);	void			ReportRaw 			(const char* iPrompt);	void			ReportError 		(const char* iPrompt);	void			ReportError			( Error& Error);	void			ReportFatalError 	(const char* iPrompt);	void			ReportProgress		(const char* iPrompt);		//void			askString (const char* iPrompt, char* oAnswer);	std::string		askString (const char* iPrompt);	double		askDoubleWithBounds	(const char* iPrompt, double iLower, double iUpper);	double		askDouble (const char* iPrompt);	double		askDouble (const char* iPrompt, answerbounds_t iNoLowerBound, double iUpperBound);	double		askDouble (const char* iPrompt, double iLowerBound, answerbounds_t iNoUpperBound);	double		askDouble (const char* iPrompt, double iLowerBound, double iUpperBound);	double      askDoubleHelper (const char* iPrompt, double iLower, double iUpper,						bool iLowerSet, bool iUpperSet);							long			askInteger 	(const char* iPrompt);	long			askIntegerWithMax 		(const char* iPrompt, long iMax);	long			askIntegerWithMin 		(const char* iPrompt, long iMin);	long			askIntegerWithBounds	(const char* iPrompt, long iMin, long iMax);		char			askChar 	(const char* iPrompt);	bool			askYesNo 	(const char* iPrompt);	bool			askYesNo (const char* iPromptCStr, bool iCurrentState);	bool			askEitherOr (const char *iPrompt, char iChoice1, char iChoice2);	int			askChoice (const char *iPrompt, char *iChoiceStr, int iCurrChoice = -1);	// DEPRECIATED & DEBUG	void			AskStringQuestion (const char* iPrompt, char* oAnswer);	std::string	AskStringQuestion (const char* iPrompt);	float			AskFloatQuestion	(const char* iPrompt);	long			AskIntQuestion 	(const char* iPrompt);	long			AskIntWithMaxQuestion 		(const char* iPrompt, long iMax);	long			AskIntWithMinQuestion 		(const char* iPrompt, long iMin);	long			AskIntWithBoundsQuestion	(const char* iPrompt, long iMin, long iMax);	char			AskCharQuestion 	(const char* iPrompt);	bool			AskYesNoQuestion 	(const char* iPrompt);	bool			AskYesNoQuestion (const char* iPromptCStr, bool iCurrentState);	bool			AskEitherOrQuestion (const char *iPrompt, char iChoice1, char iChoice2);	char			AskMultiChoice		(const char *iPrompt, char *iChoiceStr);	char			AskMultiChoice		(const char *iPrompt, char *iChoiceStr, char iCurrChoice);	char			askMultiChoice		(const char *iPrompt, char *iChoiceStr);	char			askMultiChoice		(const char *iPrompt, char *iChoiceStr, char iCurrChoice);	protected:	// for aboutbox, should define in derived class	std::string			mAppTitle;	std::string			mAppVersion;	std::string			mAppCredits;	std::vector<std::string>	mAppInfo;	// can use in derived class for custom about boxes	void		SetCols					(unsigned int iColsWidth);	void		SetBox					(unsigned int iBoxWidth);	void		SetPromptWidth			(unsigned int iPromptWidth);	void		SetCmdVisibility		(bool iCmdsVisible);	void		CalcAboutBoxIndent	();	// screen layour parameters	bool		mCmdsVisible;private:	// screen layout parameters	unsigned int	mScreenColsWidth;	unsigned int	mAboutBoxWidth;	unsigned int	mAboutBoxIndent;	unsigned int	mPromptWidth;};SBL_NAMESPACE_STOP#endif// *** END ***************************************************************/