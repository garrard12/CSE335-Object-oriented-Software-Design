/**
 * @file CityReport.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include "CityReport.h"

/**
 * Constructor
 * @param city City this report is for. 
*/
CityReport::CityReport(City* city) : mCity(city)
{
}

/**
 * Add a new city report
 * @param report ReportHolder to add
*/
void CityReport::Add(std::shared_ptr<MemberReport> report)
{
    if(mReportBins.empty() || mReportBins.back()->IsFull())
    {
        // Either we have no bins at all or the last
        // bin is full. In either case, we need a new
        // bin appended to the end of the list.
        mReportBins.push_back(std::make_shared<ReportsBin>());
    }

    // Add the report to the last bin
    mReportBins.back()->Add(report);
}

/**
 * Determine if a bin is full. This counts the number of
 * items in the bin and if it's equal to BinSize, the bin
 * is full.
 * @return true if the bin is full.
 */
bool CityReport::ReportsBin::IsFull()
{
    // Count the number of reports in the mReports array
    for(int i=0; i<=BinSize; i++)
    {
        // When we reach nullptr, we have reached the
        // end of the array.
        if(mReports[i] == nullptr)
        {
            // This is the end of the list
            return i == BinSize;
        }
    }
    return true;
}

/**
 * Add a report to this bin. We allow up to BinSize (7) reports
 * to be stored in the array mReports, followed by a nullptr. This
 * is a null-terminated array of reports.
 * @param report Report to add
 */
void CityReport::ReportsBin::Add(std::shared_ptr<MemberReport> report)
{
    for(int i=0; i<BinSize; i++)
    {
        if(mReports[i] == nullptr)
        {
            // This is the end of the list
            mReports[i] = report;
            return;
        }
    }
}
