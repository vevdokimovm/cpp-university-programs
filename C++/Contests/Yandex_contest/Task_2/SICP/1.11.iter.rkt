#lang racket
(define (iteration-fun n)
  (fun-iter n 0 1 2))

(define (fun-iter count a b c)
  (if (= count 0)
      a
      (fun-iter (- count 1) b c (+ a b c))))
        
        
(iteration-fun 5)   
     