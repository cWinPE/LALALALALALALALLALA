﻿/*********************** 
 * Drops_Test_Eng Test *
 ***********************/

import { core, data, sound, util, visual, hardware } from './lib/psychojs-2023.1.2.js';
const { PsychoJS } = core;
const { TrialHandler, MultiStairHandler } = data;
const { Scheduler } = util;
//some handy aliases as in the psychopy scripts;
const { abs, sin, cos, PI: pi, sqrt } = Math;
const { round } = util;


// store info about the experiment session:
let expName = 'drops_test_eng';  // from the Builder filename that created this script
let expInfo = {
    'participant': `${util.pad(Number.parseFloat(util.randint(0, 999999)).toFixed(0), 6)}`,
    'session': '001',
};

// Start code blocks for 'Before Experiment'
// init psychoJS:
const psychoJS = new PsychoJS({
  debug: true
});

// open window:
psychoJS.openWindow({
  fullscr: true,
  color: new util.Color([0,0,0]),
  units: 'height',
  waitBlanking: true
});
// schedule the experiment:
psychoJS.schedule(psychoJS.gui.DlgFromDict({
  dictionary: expInfo,
  title: expName
}));

const flowScheduler = new Scheduler(psychoJS);
const dialogCancelScheduler = new Scheduler(psychoJS);
psychoJS.scheduleCondition(function() { return (psychoJS.gui.dialogComponent.button === 'OK'); }, flowScheduler, dialogCancelScheduler);

// flowScheduler gets run if the participants presses OK
flowScheduler.add(updateInfo); // add timeStamp
flowScheduler.add(experimentInit);
const trialsLoopScheduler = new Scheduler(psychoJS);
flowScheduler.add(trialsLoopBegin(trialsLoopScheduler));
flowScheduler.add(trialsLoopScheduler);
flowScheduler.add(trialsLoopEnd);
flowScheduler.add(quitPsychoJS, '', true);

// quit if user presses Cancel in dialog box:
dialogCancelScheduler.add(quitPsychoJS, '', false);

psychoJS.start({
  expName: expName,
  expInfo: expInfo,
  resources: [
    // resources:
    {'name': 'conditions.xlsx', 'path': 'conditions.xlsx'},
    {'name': 'resources/Slide1.bmp', 'path': 'resources/Slide1.bmp'},
    {'name': 'resources/Slide2.bmp', 'path': 'resources/Slide2.bmp'},
    {'name': 'resources/Slide3.BMP', 'path': 'resources/Slide3.BMP'},
    {'name': 'resources/Slide4.BMP', 'path': 'resources/Slide4.BMP'},
    {'name': 'resources/Slide5.BMP', 'path': 'resources/Slide5.BMP'},
    {'name': 'resources/Slide6.BMP', 'path': 'resources/Slide6.BMP'},
    {'name': 'resources/Slide7.BMP', 'path': 'resources/Slide7.BMP'},
    {'name': 'resources/Slide8.BMP', 'path': 'resources/Slide8.BMP'},
    {'name': 'resources/Slide9.BMP', 'path': 'resources/Slide9.BMP'},
    {'name': 'resources/Slide10.BMP', 'path': 'resources/Slide10.BMP'},
    {'name': 'resources/Slide11.bmp', 'path': 'resources/Slide11.bmp'},
    {'name': 'resources/Slide36.BMP', 'path': 'resources/Slide36.BMP'},
    {'name': 'resources/Slide80.BMP', 'path': 'resources/Slide80.BMP'},
    {'name': 'resources/Slide55.BMP', 'path': 'resources/Slide55.BMP'},
    {'name': 'resources/Slide77.BMP', 'path': 'resources/Slide77.BMP'},
    {'name': 'resources/Slide33.BMP', 'path': 'resources/Slide33.BMP'},
    {'name': 'resources/Slide90.BMP', 'path': 'resources/Slide90.BMP'},
    {'name': 'resources/Slide14.BMP', 'path': 'resources/Slide14.BMP'},
    {'name': 'resources/Slide88.BMP', 'path': 'resources/Slide88.BMP'},
    {'name': 'resources/Slide32.BMP', 'path': 'resources/Slide32.BMP'},
    {'name': 'resources/Slide68.BMP', 'path': 'resources/Slide68.BMP'},
    {'name': 'resources/Slide35.BMP', 'path': 'resources/Slide35.BMP'},
    {'name': 'resources/Slide100.BMP', 'path': 'resources/Slide100.BMP'},
    {'name': 'resources/Slide46.BMP', 'path': 'resources/Slide46.BMP'},
    {'name': 'resources/Slide101.BMP', 'path': 'resources/Slide101.BMP'},
    {'name': 'resources/Slide79.BMP', 'path': 'resources/Slide79.BMP'},
    {'name': 'resources/Slide21.BMP', 'path': 'resources/Slide21.BMP'},
    {'name': 'resources/Slide76.BMP', 'path': 'resources/Slide76.BMP'},
    {'name': 'resources/Slide44.BMP', 'path': 'resources/Slide44.BMP'},
    {'name': 'resources/Slide57.BMP', 'path': 'resources/Slide57.BMP'},
    {'name': 'resources/Slide25.BMP', 'path': 'resources/Slide25.BMP'},
    {'name': 'resources/Slide87.BMP', 'path': 'resources/Slide87.BMP'},
    {'name': 'resources/Slide66.BMP', 'path': 'resources/Slide66.BMP'},
    {'name': 'resources/Slide47.BMP', 'path': 'resources/Slide47.BMP'},
    {'name': 'resources/Slide43.BMP', 'path': 'resources/Slide43.BMP'},
    {'name': 'resources/Slide65.BMP', 'path': 'resources/Slide65.BMP'},
    {'name': 'resources/Slide24.BMP', 'path': 'resources/Slide24.BMP'},
    {'name': 'resources/Slide22.BMP', 'path': 'resources/Slide22.BMP'},
    {'name': 'resources/Slide69.BMP', 'path': 'resources/Slide69.BMP'},
    {'name': 'resources/Slide91.BMP', 'path': 'resources/Slide91.BMP'},
    {'name': 'resources/Slide13.BMP', 'path': 'resources/Slide13.BMP'},
    {'name': 'resources/Slide54.BMP', 'path': 'resources/Slide54.BMP'},
    {'name': 'resources/Slide58.BMP', 'path': 'resources/Slide58.BMP'},
    {'name': 'resources/Slide41.BMP', 'path': 'resources/Slide41.BMP'},
    {'name': 'resources/Slide18.BMP', 'path': 'resources/Slide18.BMP'},
    {'name': 'resources/Slide73.BMP', 'path': 'resources/Slide73.BMP'},
    {'name': 'resources/Slide26.BMP', 'path': 'resources/Slide26.BMP'},
    {'name': 'resources/Slide92.BMP', 'path': 'resources/Slide92.BMP'},
    {'name': 'resources/Slide40.BMP', 'path': 'resources/Slide40.BMP'},
    {'name': 'resources/Slide71.BMP', 'path': 'resources/Slide71.BMP'},
    {'name': 'resources/Slide28.BMP', 'path': 'resources/Slide28.BMP'},
    {'name': 'resources/Slide38.BMP', 'path': 'resources/Slide38.BMP'},
    {'name': 'resources/Slide94.BMP', 'path': 'resources/Slide94.BMP'},
    {'name': 'resources/Slide29.BMP', 'path': 'resources/Slide29.BMP'},
    {'name': 'resources/Slide60.BMP', 'path': 'resources/Slide60.BMP'},
    {'name': 'resources/Slide70.BMP', 'path': 'resources/Slide70.BMP'},
    {'name': 'resources/Slide17.BMP', 'path': 'resources/Slide17.BMP'},
    {'name': 'resources/Slide95.BMP', 'path': 'resources/Slide95.BMP'},
    {'name': 'resources/Slide37.BMP', 'path': 'resources/Slide37.BMP'},
    {'name': 'resources/Slide81.BMP', 'path': 'resources/Slide81.BMP'},
    {'name': 'resources/Slide15.BMP', 'path': 'resources/Slide15.BMP'},
    {'name': 'resources/Slide30.BMP', 'path': 'resources/Slide30.BMP'},
    {'name': 'resources/Slide82.BMP', 'path': 'resources/Slide82.BMP'},
    {'name': 'resources/Slide16.BMP', 'path': 'resources/Slide16.BMP'},
    {'name': 'resources/Slide84.BMP', 'path': 'resources/Slide84.BMP'},
    {'name': 'resources/Slide93.BMP', 'path': 'resources/Slide93.BMP'},
    {'name': 'resources/Slide48.BMP', 'path': 'resources/Slide48.BMP'},
    {'name': 'resources/Slide85.BMP', 'path': 'resources/Slide85.BMP'},
    {'name': 'resources/Slide50.BMP', 'path': 'resources/Slide50.BMP'},
    {'name': 'resources/Slide99.BMP', 'path': 'resources/Slide99.BMP'},
    {'name': 'resources/Slide39.BMP', 'path': 'resources/Slide39.BMP'},
    {'name': 'resources/Slide72.BMP', 'path': 'resources/Slide72.BMP'},
    {'name': 'resources/Slide64.BMP', 'path': 'resources/Slide64.BMP'},
    {'name': 'resources/Slide31.BMP', 'path': 'resources/Slide31.BMP'},
    {'name': 'resources/Slide62.BMP', 'path': 'resources/Slide62.BMP'},
    {'name': 'resources/Slide49.BMP', 'path': 'resources/Slide49.BMP'},
    {'name': 'resources/Slide83.BMP', 'path': 'resources/Slide83.BMP'},
    {'name': 'resources/Slide59.BMP', 'path': 'resources/Slide59.BMP'},
    {'name': 'resources/Slide51.BMP', 'path': 'resources/Slide51.BMP'},
    {'name': 'resources/Slide97.BMP', 'path': 'resources/Slide97.BMP'},
    {'name': 'resources/Slide20.BMP', 'path': 'resources/Slide20.BMP'},
    {'name': 'resources/Slide98.BMP', 'path': 'resources/Slide98.BMP'},
    {'name': 'resources/Slide86.BMP', 'path': 'resources/Slide86.BMP'},
    {'name': 'resources/Slide52.BMP', 'path': 'resources/Slide52.BMP'},
    {'name': 'resources/Slide63.BMP', 'path': 'resources/Slide63.BMP'},
    {'name': 'resources/Slide42.BMP', 'path': 'resources/Slide42.BMP'},
    {'name': 'resources/Slide75.BMP', 'path': 'resources/Slide75.BMP'},
    {'name': 'resources/Slide96.BMP', 'path': 'resources/Slide96.BMP'},
    {'name': 'resources/Slide53.BMP', 'path': 'resources/Slide53.BMP'},
    {'name': 'resources/Slide19.BMP', 'path': 'resources/Slide19.BMP'},
    {'name': 'resources/Slide74.BMP', 'path': 'resources/Slide74.BMP'},
    {'name': 'resources/Slide61.BMP', 'path': 'resources/Slide61.BMP'},
    {'name': 'resources/Slide27.BMP', 'path': 'resources/Slide27.BMP'},
    {'name': 'resources/Slide102.bmp', 'path': 'resources/Slide102.bmp'},
    {'name': 'default.png', 'path': 'https://pavlovia.org/assets/default/default.png'},
  ]
});

psychoJS.experimentLogger.setLevel(core.Logger.ServerLevel.EXP);


var currentLoop;
var frameDur;
async function updateInfo() {
  currentLoop = psychoJS.experiment;  // right now there are no loops
  expInfo['date'] = util.MonotonicClock.getDateStr();  // add a simple timestamp
  expInfo['expName'] = expName;
  expInfo['psychopyVersion'] = '2023.1.2';
  expInfo['OS'] = window.navigator.platform;


  // store frame rate of monitor if we can measure it successfully
  expInfo['frameRate'] = psychoJS.window.getActualFrameRate();
  if (typeof expInfo['frameRate'] !== 'undefined')
    frameDur = 1.0 / Math.round(expInfo['frameRate']);
  else
    frameDur = 1.0 / 60.0; // couldn't get a reliable measure so guess

  // add info from the URL:
  util.addInfoFromUrl(expInfo);
  

  
  psychoJS.experiment.dataFileName = (("." + "/") + `data/${expInfo["participant"]}_${expName}_${expInfo["date"]}`);


  return Scheduler.Event.NEXT;
}


var trialClock;
var response;
var Trial;
var globalClock;
var routineTimer;
async function experimentInit() {
  // Initialize components for Routine "trial"
  trialClock = new util.Clock();
  response = new core.Keyboard({psychoJS: psychoJS, clock: new util.Clock(), waitForStart: true});
  
  Trial = new visual.ImageStim({
    win : psychoJS.window,
    name : 'Trial', units : undefined, 
    image : 'default.png', mask : undefined,
    anchor : 'center',
    ori : 0.0, pos : [0, 0], size : [1.5, 1],
    color : new util.Color([1,1,1]), opacity : undefined,
    flipHoriz : false, flipVert : false,
    texRes : 128.0, interpolate : true, depth : -1.0 
  });
  // Create some handy timers
  globalClock = new util.Clock();  // to track the time since experiment started
  routineTimer = new util.CountdownTimer();  // to track time remaining of each (non-slip) routine
  
  return Scheduler.Event.NEXT;
}


var trials;
function trialsLoopBegin(trialsLoopScheduler, snapshot) {
  return async function() {
    TrialHandler.fromSnapshot(snapshot); // update internal variables (.thisN etc) of the loop
    
    // set up handler to look after randomisation of conditions etc
    trials = new TrialHandler({
      psychoJS: psychoJS,
      nReps: 1, method: TrialHandler.Method.SEQUENTIAL,
      extraInfo: expInfo, originPath: undefined,
      trialList: 'conditions.xlsx',
      seed: undefined, name: 'trials'
    });
    psychoJS.experiment.addLoop(trials); // add the loop to the experiment
    currentLoop = trials;  // we're now the current loop
    
    // Schedule all the trials in the trialList:
    for (const thisTrial of trials) {
      snapshot = trials.getSnapshot();
      trialsLoopScheduler.add(importConditions(snapshot));
      trialsLoopScheduler.add(trialRoutineBegin(snapshot));
      trialsLoopScheduler.add(trialRoutineEachFrame());
      trialsLoopScheduler.add(trialRoutineEnd(snapshot));
      trialsLoopScheduler.add(trialsLoopEndIteration(trialsLoopScheduler, snapshot));
    }
    
    return Scheduler.Event.NEXT;
  }
}


async function trialsLoopEnd() {
  // terminate loop
  psychoJS.experiment.removeLoop(trials);
  // update the current loop from the ExperimentHandler
  if (psychoJS.experiment._unfinishedLoops.length>0)
    currentLoop = psychoJS.experiment._unfinishedLoops.at(-1);
  else
    currentLoop = psychoJS.experiment;  // so we use addData from the experiment
  return Scheduler.Event.NEXT;
}


function trialsLoopEndIteration(scheduler, snapshot) {
  // ------Prepare for next entry------
  return async function () {
    if (typeof snapshot !== 'undefined') {
      // ------Check if user ended loop early------
      if (snapshot.finished) {
        // Check for and save orphaned data
        if (psychoJS.experiment.isEntryEmpty()) {
          psychoJS.experiment.nextEntry(snapshot);
        }
        scheduler.stop();
      } else {
        psychoJS.experiment.nextEntry(snapshot);
      }
    return Scheduler.Event.NEXT;
    }
  };
}


var t;
var frameN;
var continueRoutine;
var _response_allKeys;
var trialComponents;
function trialRoutineBegin(snapshot) {
  return async function () {
    TrialHandler.fromSnapshot(snapshot); // ensure that .thisN vals are up to date
    
    //--- Prepare to start Routine 'trial' ---
    t = 0;
    trialClock.reset(); // clock
    frameN = -1;
    continueRoutine = true; // until we're told otherwise
    // update component parameters for each repeat
    response.keys = undefined;
    response.rt = undefined;
    _response_allKeys = [];
    Trial.setImage(TrialName);
    // keep track of which components have finished
    trialComponents = [];
    trialComponents.push(response);
    trialComponents.push(Trial);
    
    for (const thisComponent of trialComponents)
      if ('status' in thisComponent)
        thisComponent.status = PsychoJS.Status.NOT_STARTED;
    return Scheduler.Event.NEXT;
  }
}


function trialRoutineEachFrame() {
  return async function () {
    //--- Loop for each frame of Routine 'trial' ---
    // get current time
    t = trialClock.getTime();
    frameN = frameN + 1;// number of completed frames (so 0 is the first frame)
    // update/draw components on each frame
    
    // *response* updates
    if (t >= 0.25 && response.status === PsychoJS.Status.NOT_STARTED) {
      // keep track of start time/frame for later
      response.tStart = t;  // (not accounting for frame time here)
      response.frameNStart = frameN;  // exact frame index
      
      // keyboard checking is just starting
      psychoJS.window.callOnFlip(function() { response.clock.reset(); });  // t=0 on next screen flip
      psychoJS.window.callOnFlip(function() { response.start(); }); // start on screen flip
      psychoJS.window.callOnFlip(function() { response.clearEvents(); });
    }

    if (response.status === PsychoJS.Status.STARTED) {
      let theseKeys = response.getKeys({keyList: ['f', 'j', 'space'], waitRelease: false});
      _response_allKeys = _response_allKeys.concat(theseKeys);
      if (_response_allKeys.length > 0) {
        response.keys = _response_allKeys[0].name;  // just the first key pressed
        response.rt = _response_allKeys[0].rt;
        // was this correct?
        if (response.keys == CorrAns) {
            response.corr = 1;
        } else {
            response.corr = 0;
        }
        // a response ends the routine
        continueRoutine = false;
      }
    }
    
    
    // *Trial* updates
    if (t >= 0.25 && Trial.status === PsychoJS.Status.NOT_STARTED) {
      // keep track of start time/frame for later
      Trial.tStart = t;  // (not accounting for frame time here)
      Trial.frameNStart = frameN;  // exact frame index
      
      Trial.setAutoDraw(true);
    }

    // check for quit (typically the Esc key)
    if (psychoJS.experiment.experimentEnded || psychoJS.eventManager.getKeys({keyList:['escape']}).length > 0) {
      return quitPsychoJS('The [Escape] key was pressed. Goodbye!', false);
    }
    
    // check if the Routine should terminate
    if (!continueRoutine) {  // a component has requested a forced-end of Routine
      return Scheduler.Event.NEXT;
    }
    
    continueRoutine = false;  // reverts to True if at least one component still running
    for (const thisComponent of trialComponents)
      if ('status' in thisComponent && thisComponent.status !== PsychoJS.Status.FINISHED) {
        continueRoutine = true;
        break;
      }
    
    // refresh the screen if continuing
    if (continueRoutine) {
      return Scheduler.Event.FLIP_REPEAT;
    } else {
      return Scheduler.Event.NEXT;
    }
  };
}


function trialRoutineEnd(snapshot) {
  return async function () {
    //--- Ending Routine 'trial' ---
    for (const thisComponent of trialComponents) {
      if (typeof thisComponent.setAutoDraw === 'function') {
        thisComponent.setAutoDraw(false);
      }
    }
    // was no response the correct answer?!
    if (response.keys === undefined) {
      if (['None','none',undefined].includes(CorrAns)) {
         response.corr = 1;  // correct non-response
      } else {
         response.corr = 0;  // failed to respond (incorrectly)
      }
    }
    // store data for current loop
    // update the trial handler
    if (currentLoop instanceof MultiStairHandler) {
      currentLoop.addResponse(response.corr, level);
    }
    psychoJS.experiment.addData('response.keys', response.keys);
    psychoJS.experiment.addData('response.corr', response.corr);
    if (typeof response.keys !== 'undefined') {  // we had a response
        psychoJS.experiment.addData('response.rt', response.rt);
        routineTimer.reset();
        }
    
    response.stop();
    // the Routine "trial" was not non-slip safe, so reset the non-slip timer
    routineTimer.reset();
    
    // Routines running outside a loop should always advance the datafile row
    if (currentLoop === psychoJS.experiment) {
      psychoJS.experiment.nextEntry(snapshot);
    }
    return Scheduler.Event.NEXT;
  }
}


function importConditions(currentLoop) {
  return async function () {
    psychoJS.importAttributes(currentLoop.getCurrentTrial());
    return Scheduler.Event.NEXT;
    };
}


async function quitPsychoJS(message, isCompleted) {
  // Check for and save orphaned data
  if (psychoJS.experiment.isEntryEmpty()) {
    psychoJS.experiment.nextEntry();
  }
  psychoJS.window.close();
  psychoJS.quit({message: message, isCompleted: isCompleted});
  
  return Scheduler.Event.QUIT;
}
