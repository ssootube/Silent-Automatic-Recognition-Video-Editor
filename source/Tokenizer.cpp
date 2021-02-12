#include "Tokenizer.h"

Tokenizer::Tokenizer(const Int16* samples, Uint64 samples_length, int threshold, unsigned int rate)
	:samples(samples),samples_length(samples_length),threshold(threshold),rate(rate)
{
}

void Tokenizer::analyze(int sampling)
{
	long double time = 0;
	long double start = 0;
	long double end = 0;
	int count = 0;
	for (long i = 0; i * sampling < samples_length; ++i) 
	{
		time += sampling / (long double)rate;
		if (count < mute_count && abs(samples[i * sampling]) >= threshold) 
		{
			count = 0;
			end = time - sampling / (long double)rate;
			push(start, end, false);
			start = end;
			continue;
		}
		else if (count >= mute_count && abs(samples[i * sampling]) >= threshold) 
		{
			cout << i * sampling <<"/"<< samples_length << "\n";
			end = time - sampling / (long double)rate;
			push(start, end, true);
			start = end;
			count = 0;
		}
		if (abs(samples[i * sampling]) < threshold) 
		{
			count++;
		}
	}
}

void Tokenizer::push(float start, float end, bool is_silent)
{
	if (cuts.empty())
		cuts.push_back(Cut(start, end, is_silent));
	else if (cuts.back().is_silent != is_silent)
		cuts.push_back(Cut(start, end, is_silent));
	else
		cuts[cuts.size() - 1].set_end(end);
}

size_t Tokenizer::getCutsSize()
{
	return cuts.size();
}

void Tokenizer::setFillColor(size_t selected, Color color)
{
	if (selected < 0 || selected >= cuts.size())
		return;
	if (color == Color::Blue)
		cuts[selected].rect.setFillColor(color);
	else
		cuts[selected].rect.setFillColor(cuts[selected].is_silent ? Color::Red : Color::Green);
}

void Tokenizer::setPosition(Vector2f pos, size_t i)
{
	cuts[i].rect.setPosition(pos);
}

float Tokenizer::getStart(size_t selected)
{
	if (selected < 0 || selected >= cuts.size())
		return cuts.back().end;
	return cuts[selected].start;
}

float Tokenizer::getEnd(size_t selected)
{
	if (selected < 0 || selected >= cuts.size())
		return 0;
	return cuts[selected].end;
}

void Tokenizer::toggleSilent(size_t idx)
{
	if (idx < 0 || idx >= cuts.size())
		return;
	cuts[idx].is_silent = !cuts[idx].is_silent;
	cuts[idx].rect.setFillColor(cuts[idx].is_silent ? Color::Red : Color::Green);
}

void Tokenizer::draw(RenderWindow& window, size_t i)
{
	if (i < 0 || i >= cuts.size())
		return;
	window.draw(cuts[i].rect);
}

void Tokenizer::chop(string title)
{
	ofstream txt(".\\temp\\filelist.txt", ios::out);
	int count = 0;
	for (auto& iter : cuts) {
		if (iter.is_silent) continue;
		else {
			txt << "file .\\temp\\" << title;	txt << count; txt << ".mp4\n";
			string temp = "ffmpeg -ss " + to_string(round(iter.start * 100) / 100.0) + " -i " + title + ".mp4 -t " + to_string(round((iter.end - iter.start) * 100) / 100.0) + " -vcodec libx264 -acodec aac " + ".\\temp\\" + title + to_string(count) + ".mp4";
			system(temp.c_str());
			count++;
		}
	}
	txt.close();
	system("ffmpeg -f concat -i .\\temp\\filelist.txt -c copy output.mp4");
}

void Tokenizer::remove(string title)
{
	ifstream del("filelist.txt", ios::in);
	char del_buf[256];
	while (del.getline(del_buf, 256)) {
		string temp = "del " + string(del_buf);
		system(temp.c_str());
	}
	system("del .\\temp\\filelist.txt");
	string ending = "del .\\temp\\" + title + ".wav";
	system(ending.c_str());
}
