#include <bits/stdc++.h>
using namespace std;

bool isLost()
{
    return rand() % 2 < 1; // Simulate packet loss with 20% probability
}

void stopAndWaitARQ(int frames)
{
    cout << "\n---Stop and Wait ARQ---\n";
    for (int i = 0; i < frames; i++)
    {
        cout << "Sending frame " << i << "...";
        if (isLost())
        {
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Frame lost! Resending...\n";
            i--; // Retry sending the same frame
        }
        else
        {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Acknowledgement received.\n";
        }
    }
}

void goBackNARQ(int frames, int windowSize)
{
    cout << "\n---Go Back N ARQ---\n";
    int base = 0;
    while (base < frames)
    {
        cout << "Sending frames from " << base << " to " << min(base + windowSize - 1, frames - 1) << "...\n";
        int i;
        for (i = base; i < min(base + windowSize, frames); i++)
        {
            if (isLost())
            {
                cout << "Frame " << i << " lost! Resending from frame " << i << endl;
                this_thread::sleep_for(chrono::seconds(2));
                break; // Stop sending if a frame is lost
            }
            else
            {
                cout << "Acknowledgement received for frame " << i << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
            }
        }
        base = i; // Update base to the next frame to be sent
    }
}

void selectiveRepeatARQ(int frames, int windowSize)
{
    cout << "\n---Selective-Repeat ARQ (Selective Reject)---\n";
    vector<bool> ack(frames, false);
    int base = 0;
    while (base < frames)
    {
        for (int i = base; i < min(base + windowSize, frames); i++)
        {
            if (!ack[i])
            {
                cout << "Sending frame " << i << "...";
                if (isLost())
                {
                    cout << "Frame lost! Resending later.\n";
                    this_thread::sleep_for(chrono::seconds(2));
                }
                else
                {
                    cout << "Acknowledgement received for frame " << i << endl;
                    ack[i] = true;
                    this_thread::sleep_for(chrono::milliseconds(500));
                }
            }
        }
        while (base < frames && ack[base])
            base++; // Move the base pointer to the next unacknowledged frame
    }
}

int main()
{
    srand(time(0));
    int totalFrames, windowSize;
    int choice;

    cout << "Enter number of total Frames: ";
    cin >> totalFrames;

    cout << "Enter window size for Go Back N and Selective-Repeat ARQ: ";
    cin >> windowSize;

    do
    {
        // Menu-driven interface
        cout << "\n---ARQ Techniques Simulation---\n";
        cout << "1. Stop and Wait ARQ\n";
        cout << "2. Go Back N ARQ\n";
        cout << "3. Selective Repeat ARQ\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            stopAndWaitARQ(totalFrames);
            break;
        case 2:
            goBackNARQ(totalFrames, windowSize);
            break;
        case 3:
            selectiveRepeatARQ(totalFrames, windowSize);
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please select again.\n";
            break;
        }

    } while (choice != 4); // Repeat until user chooses to exit

    return 0;
}
