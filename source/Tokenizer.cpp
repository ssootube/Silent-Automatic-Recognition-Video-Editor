#include "Tokenizer.h"

void Tokenizer::analyze(Option &op, int sampling)
{
	long double time = 0;
	long double start = 0;
	long double end = 0;
	int count = 0;
	for (long i = 0; i * sampling < op.samples_length; ++i) 
	{
		time += sampling / (long double)op.rate;
		if (count < mute_count && abs(op.samples[i * sampling]) >= op.threshold) 
		{
			count = 0;
			end = time - sampling / (long double)op.rate;
			push(op, start, end, false);
			start = end;
			continue;
		}
		else if (count >= mute_count && abs(op.samples[i * sampling]) >= op.threshold) 
		{
			cout << i * sampling <<"/"<< op.samples_length << "\n";
			end = time - sampling / (long double)op.rate;
			push(op, start, end, true);
			start = end;
			count = 0;
		}
		if (abs(op.samples[i * sampling]) < op.threshold) 
		{
			count++;
		}
	}
}

void Tokenizer::push(Option& op, float start, float end, bool is_silent)
{
	if (op.cuts.empty())
		op.cuts.push_back(Cut(start, end, is_silent));
	else if (op.cuts.back().is_silent != is_silent)
		op.cuts.push_back(Cut(start, end, is_silent));
	else
		op.cuts[op.cuts.size() - 1].set_end(end);
}

void Tokenizer::chop(Option& op)
{

	ofstream txt(".\\temp\\filelist.txt", ios::out);
	ofstream log(".\\temp\\log.txt", ios::out);
	int count = 0;
	for (auto& iter : op.cuts) {
		if (iter.is_silent) continue;
		else {
			txt << "file .\\\\temp\\\\" << op.title;	txt << count; txt << ".mp4\n";
			string temp = "ffmpeg -ss " + to_string(round(iter.start * 100) / 100.0) + " -i " + op.title + ".mp4 -t " + to_string(round((iter.end - iter.start) * 100) / 100.0) + " -vcodec libx264 -acodec aac " + ".\\temp\\" + op.title + to_string(count) + ".mp4";
			log << temp << endl;
			system(temp.c_str());
			count++;
		}
	}
	log.close();
	txt.close();
	system("ffmpeg -f concat -safe 0 -i .\\temp\\filelist.txt -c copy output.mp4");
}